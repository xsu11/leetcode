package com.xinsu;

public class Q622_DesignCircularQueue {

    private final int[] queueArray;
    private int front = 0;
    private int rear = -1;
    private int size = 0;

    public Q622_DesignCircularQueue(int k) {
        this.queueArray = new int[k];
    }

    public boolean enQueue(int value) {
        if (isFull()) {
            return false;
        }

        this.rear = (this.rear + 1) % this.queueArray.length;
        this.queueArray[this.rear] = value;
        this.size++;

        return true;
    }

    public boolean deQueue() {
        if (isEmpty()) {
            return false;
        }

        this.queueArray[this.front] = 0;
        this.front = (this.front + 1) % this.queueArray.length;
        this.size--;

        return true;
    }

    public int Front() {
        return isEmpty() ? -1 : this.queueArray[this.front];
    }

    public int Rear() {
        return isEmpty() ? -1 : this.queueArray[this.rear];
    }

    public boolean isEmpty() {
        return this.size == 0;
    }

    public boolean isFull() {
        return this.queueArray.length == this.size;
    }

}
