package com.xinsu.util;

public class Node {

    public int key;
    public int value;
    public Node prev;
    public Node next;

    public Node() {
    }

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
