package com.xinsu.designpattern.observer;

public class ConcreteObserver2 implements Observer {

    @Override
    public void update(final Object r) {
        // TODO: perform actual update here
        System.out.println("observer 2");
    }

}
