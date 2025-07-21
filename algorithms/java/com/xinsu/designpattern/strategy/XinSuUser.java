package com.xinsu.designpattern.strategy;

public class XinSuUser {

    private final Strategy strategy;

    public XinSuUser(Strategy strategy) {
        this.strategy = strategy;
    }

    public Strategy getStrategy() {
        return strategy;
    }

}
