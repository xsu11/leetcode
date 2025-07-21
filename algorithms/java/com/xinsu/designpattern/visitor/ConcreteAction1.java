package com.xinsu.designpattern.visitor;

public class ConcreteAction1 implements Action {

    @Override
    public void accept(Visitor visitor) {
        visitor.visit(this);
    }

}
