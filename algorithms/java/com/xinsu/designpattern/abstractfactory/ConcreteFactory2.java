package com.xinsu.designpattern.abstractfactory;

public class ConcreteFactory2 implements Factory {

    @Override
    public Product createProduct() {
        return new ConcreteProduct2();
    }

    @Override
    public Service createService() {
        return new ConcreteService2();
    }

}
