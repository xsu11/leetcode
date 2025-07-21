package com.xinsu.designpattern.visitor;

public class ConcreteVisitor2 implements Visitor {

    @Override
    public void visit(ConcreteAction1 action) {
        System.out.println("concrete visitor 2 does concrete action 1");
    }

    @Override
    public void visit(ConcreteAction2 action) {
        System.out.println("concrete visitor 2 does concrete action 2");
    }

}
