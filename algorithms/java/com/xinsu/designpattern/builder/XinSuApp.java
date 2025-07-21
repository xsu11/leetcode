package com.xinsu.designpattern.builder;

public class XinSuApp {

    public static void main(String[] args) {
        final Config.Builder configBuilder = new Config.Builder()
                .setRequired1("required")
                .setOptional1("optional1");

        // TODO: can perform other logic here

        final Config config = configBuilder.setRequired2(10)
                .setOptional2("optional2")
                .build();
    }

}
