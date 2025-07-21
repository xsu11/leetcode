package com.xinsu.designpattern.factory;

public class XinSuApp {

    public static void main(String[] args) {
        Factory factory1 = FactoryCreator.getFactory("concrete factory 1");
        Item item1 = factory1.createItem();

        Factory factory2 = FactoryCreator.getFactory("concrete factory 2");
        Item item2 = factory2.createItem();
    }

}
