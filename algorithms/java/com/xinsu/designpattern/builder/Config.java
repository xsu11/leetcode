package com.xinsu.designpattern.builder;

public class Config {

    public static class Builder {

        // required fields
        private String required1;
        private int required2;

        // optional fields
        private String optional1;
        private String optional2;

        public Builder setRequired1(String required1) {
            // TODO: add validation here
            this.required1 = required1;
            return this;
        }

        public Builder setRequired2(int required2) {
            // TODO: add validation here
            this.required2 = required2;
            return this;
        }

        public Builder setOptional1(String optional1) {
            // TODO: add validation here
            this.optional1 = optional1;
            return this;
        }

        public Builder setOptional2(String optional2) {
            // TODO: add validation here
            this.optional2 = optional2;
            return this;
        }

        public Config build() {
            // TODO: validate required field
            return new Config(this);
        }

    }

    private String required1;
    private int required2;

    private String optional1;
    private String optional2;

    private Config(final Builder builder) {
        this.required1 = builder.required1;
        this.required2 = builder.required2;

        this.optional1 = builder.optional1;
        this.optional2 = builder.optional2;
    }

    public String getRequired1() {
        return this.required1;
    }

    public int getRequired2() {
        return this.required2;
    }

    public String getOptional1() {
        return this.optional1;
    }

    public String getOptional2() {
        return this.optional2;
    }

}
