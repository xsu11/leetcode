package com.xinsu.designpattern.strategy;

public class XinSuApp {

    public static void main(String[] args) {
        Strategy strategy = StrategyFactory.getStrategy("concrete strategy 1");
        XinSuUser xinSuUser = new XinSuUser(strategy);
    }

}
