package com.xinsu.designpattern.visitor;

import java.util.ArrayList;
import java.util.List;

public class XinSuApp {

    public static void main(String[] args) {
        List<Action> actions = getActions();

        ConcreteVisitor1 visitor1 = new ConcreteVisitor1();
        actions.forEach(action -> action.accept(visitor1));

        ConcreteVisitor2 visitor2 = new ConcreteVisitor2();
        actions.forEach(action -> action.accept(visitor2));
    }

    private static List<Action> getActions() {
        final List<Action> actions = new ArrayList<>();
        actions.add(new ConcreteAction1());
        actions.add(new ConcreteAction2());
        return actions;
    }

}
