package com.xinsu.designpattern.strategy;

import java.util.HashMap;
import java.util.Map;

public class StrategyFactory {

    private static final Map<String, Strategy> strategies = new HashMap<>();
    static {
        strategies.put("concrete strategy 1", new ConcreteStrategy1());
        strategies.put("concrete strategy2", new ConcreteStrategy2());
    }

    public static Strategy getStrategy(String type) {
        if (type == null || type.isEmpty()) {
            return null;
        }

        return strategies.get(type);
    }

}
