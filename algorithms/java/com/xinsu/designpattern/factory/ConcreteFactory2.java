package com.xinsu.designpattern.factory;

public class ConcreteFactory2 implements Factory {

    @Override
    public Item createItem() {
        return new ConcreteItem2();
    }

}
