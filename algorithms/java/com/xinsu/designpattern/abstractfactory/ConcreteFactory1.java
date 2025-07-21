package com.xinsu.designpattern.abstractfactory;

public class ConcreteFactory1 implements Factory {

    @Override
    public Product createProduct() {
        return new ConcreteProduct1();
    }

    @Override
    public Service createService() {
        return new ConcreteService1();
    }

}
