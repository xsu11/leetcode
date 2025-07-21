package com.xinsu.util.interview.asynctaskexecutor;

/**
 * 设计一个异步任务执行器（内部线程池控制并发度），支持注册回调函数，在任务完成时自动调用相应的回调函数。 实现一个异步任务执行器类，
 * 包含以下功能：
 * void registerTask(std::function<void()> task, std::function<void()> callback) ：注册一个任务及其对应的回调函数。
 * void start() ：启动任务执行器，执行所有注册的任务，并在任务完成时调用相应的回调函数。
*/

public class TaskResult {

    private final String taskResult;
    private final TaskException taskException;

    private final String callbackResult;
    private final CallbackException callbackException;

    public TaskResult(
            final String taskResult,
            final TaskException taskException,
            final String callbackResult,
            final CallbackException callbackException) {
        this.taskResult = taskResult;
        this.taskException = taskException;

        this.callbackResult = callbackResult;
        this.callbackException = callbackException;
    }

    public static TaskResult getTaskException(final TaskException taskException) {
        return new TaskResult(null, taskException, null, null);
    }

    public static TaskResult getCallBackException(
            final String taskResult,
            final CallbackException callbackException) {
        return new TaskResult(taskResult, null, null, callbackException);
    }

    public static TaskResult getResult(final String taskResult, final String callbackResult) {
        return new TaskResult(taskResult, null, callbackResult, null);
    }

    public String getTaskResult() {
        return this.taskResult;
    }

    public TaskException getTaskException() {
        return this.taskException;
    }

    public String getCallbackResult() {
        return this.callbackResult;
    }

    public CallbackException getCallbackException() {
        return this.callbackException;
    }

}
