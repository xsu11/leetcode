package com.xinsu.designpattern.observer;

import java.util.ArrayList;
import java.util.List;

public class ConcreteSubject implements Subject {

    private final List<Observer> observers = new ArrayList<>();

    @Override
    public void register(final Observer observer) {
        this.observers.add(observer);
    }

    @Override
    public void unregister(final Observer observer) {
        this.observers.remove(observer);
    }

    @Override
    public void notifyOneObserver(final Object r) {
        if (this.observers.isEmpty()) {
            return;
        }

        final Observer observer = this.observers.remove(0);
        observer.update(r);
    }

    @Override
    public void notifyAllObservers(final Object r) {
        this.observers.forEach(observer -> observer.update(r));
    }

}
