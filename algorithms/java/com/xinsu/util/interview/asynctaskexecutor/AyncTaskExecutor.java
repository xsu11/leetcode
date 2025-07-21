package com.xinsu.util.interview.asynctaskexecutor;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;
import java.util.function.Function;
import java.util.function.Supplier;

public class AyncTaskExecutor {

    private final static int AVAILABLE_PROCESSORS = Runtime.getRuntime().availableProcessors();

    private static final class TaskExecutorHolder {
        static final AyncTaskExecutor taskExecutor = new AyncTaskExecutor();
    }

    public static AyncTaskExecutor getInstance() {
        return TaskExecutorHolder.taskExecutor;
    }

    private volatile ThreadPoolExecutor threadPoolExecutor;

    // task -> callback
    private final ConcurrentHashMap<Supplier<String>, Function<String, String>> taskCallbacks;
    // task -> taskFuture
    private final ConcurrentHashMap<Supplier<String>, CompletableFuture<String>> taskFutures;
    // task -> callbackFuture
    private final ConcurrentHashMap<Supplier<String>, CompletableFuture<String>> callbackFutures;
    // task -> task result
    private final ConcurrentHashMap<Supplier<String>, TaskResult> taskResults;

    private AyncTaskExecutor() {
        this.threadPoolExecutor = null;

        this.taskCallbacks = new ConcurrentHashMap<>();
        this.taskFutures = new ConcurrentHashMap<>();
        this.callbackFutures = new ConcurrentHashMap<>();
        this.taskResults = new ConcurrentHashMap<>();
    }

    public void startService() {
        if (this.threadPoolExecutor == null) {
            this.threadPoolExecutor = new ThreadPoolExecutor(
                    AVAILABLE_PROCESSORS,
                    AVAILABLE_PROCESSORS * 2,
                    1,
                    TimeUnit.MINUTES,
                    new LinkedBlockingQueue<>(5),
                    new ThreadPoolExecutor.CallerRunsPolicy());
        }
    }

    public void stopService() {
        if (this.threadPoolExecutor != null) {
            this.threadPoolExecutor.shutdown();
            this.threadPoolExecutor = null;
        }
    }

    public void registerTask(
            final Supplier<String> task,
            final Function<String, String> callback) {
        this.taskCallbacks.put(task, callback);
    }

    public void start() {
        this.taskCallbacks.forEach((task, callback) -> {
            final CompletableFuture<String> taskFuture = CompletableFuture
                    .supplyAsync(task, this.threadPoolExecutor);
            this.taskFutures.put(task, taskFuture);

            final CompletableFuture<String> callbackFuture = taskFuture
                    .thenApplyAsync(callback, this.threadPoolExecutor);
            this.callbackFutures.put(task, callbackFuture);
        });
    }

    public TaskResult getResult(final Supplier<String> task) throws ExecutionException, InterruptedException {
        if (this.taskResults.containsKey(task)) {
            return this.taskResults.get(task);
        }

        final String taskResult;
        try {
            taskResult = this.taskFutures.get(task).get();
        } catch (final Exception e) {
            final TaskResult result = TaskResult.getTaskException(new TaskException(e.getMessage(), e.getCause()));
            this.taskResults.put(task, result);
            return result;
        }

        final String callbackResult;
        try {
            callbackResult = this.callbackFutures.get(task).get();
        } catch (final Exception e) {
            final TaskResult result = TaskResult.getCallBackException(
                    taskResult,
                    new CallbackException(e.getMessage(), e.getCause()));
            this.taskResults.put(task, result);
            return result;
        }

        final TaskResult result = TaskResult.getResult(taskResult, callbackResult);
        this.taskResults.put(task, result);
        return result;
    }

}
