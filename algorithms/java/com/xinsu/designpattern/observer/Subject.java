package com.xinsu.designpattern.observer;

public interface Subject {

    void register(Observer observer);

    void unregister(Observer observer);

    void notifyOneObserver(Object r);

    void notifyAllObservers(Object r);

}
