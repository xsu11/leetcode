package com.xinsu.designpattern.observer;

public class XinSuApp {

    public static void main(String[] args) {
        ConcreteSubject subject = new ConcreteSubject();
        subject.register(new ConcreteObserver1());
        subject.register(new ConcreteObserver2());

        // TODO: perform any additional actions on subject

        subject.notifyAllObservers("actions on subject done");
    }

}
