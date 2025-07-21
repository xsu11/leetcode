package com.xinsu.util.interview.asynctaskexecutor;

public class TaskException extends Exception {

    public TaskException(final String message) {
        super(message);
    }

    public TaskException(final String message, final Throwable rootCause) {
        super(message, rootCause);
    }

}
