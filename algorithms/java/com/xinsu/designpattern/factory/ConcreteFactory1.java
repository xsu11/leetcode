package com.xinsu.designpattern.factory;

public class ConcreteFactory1 implements Factory {

    @Override
    public Item createItem() {
        return new ConcreteItem1();
    }

}
