package com.xinsu.util.interview.asynctaskexecutor;

public class CallbackException extends Exception {

    public CallbackException(final String message) {
        super(message);
    }

    public CallbackException(final String message, final Throwable rootCause) {
        super(message, rootCause);
    }

}
