package com.xinsu.designpattern.visitor;

public interface Visitor {

    void visit(ConcreteAction1 action);
    void visit(ConcreteAction2 action);

}
