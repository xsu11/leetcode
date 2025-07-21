package com.xinsu.designpattern.visitor;

public class ConcreteVisitor1 implements Visitor {

    @Override
    public void visit(ConcreteAction1 action) {
        System.out.println("concrete visitor 1 does concrete action 1");
    }

    @Override
    public void visit(ConcreteAction2 action) {
        System.out.println("concrete visitor 1 does concrete action 2");
    }

}
