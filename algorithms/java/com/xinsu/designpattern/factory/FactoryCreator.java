package com.xinsu.designpattern.factory;

import java.util.HashMap;
import java.util.Map;

public class FactoryCreator {

    private static final Map<String, Factory> concreteFactories = new HashMap<>();
    static {
        concreteFactories.put("concrete factory 1", new ConcreteFactory1());
        concreteFactories.put("concrete factory 2", new ConcreteFactory2());
    }

    public static Factory getFactory(final String type) {
        if (type == null || type.isEmpty()) {
            return null;
        }

        return concreteFactories.get(type);
    }

}
