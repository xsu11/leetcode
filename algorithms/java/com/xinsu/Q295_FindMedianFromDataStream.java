package com.xinsu;

import java.util.PriorityQueue;

public class Q295_FindMedianFromDataStream {

    // min heap by default
    private final PriorityQueue<Integer> largeHeap = new PriorityQueue<>((a, b) -> a - b);
    // max heap
    private final PriorityQueue<Integer> smallHeap = new PriorityQueue<>((a, b) -> b - a);

    public Q295_FindMedianFromDataStream() {
    }

    public void addNum(int num) {
        // boundary case
        if (largeHeap.isEmpty()) { // smallHeap must be empty as well
            largeHeap.offer(num);
        } else {
            // 1. either largeHeap.size() == smallHeap.size(),
            // 2. or largeHeap.size() == smallHeap.size() + 1
            if (largeHeap.peek() < num) {
                largeHeap.offer(num);
            } else {
                smallHeap.offer(num);
            }

            // 1. largeHeap.size() == smallHeap.size():
            // either largeHeap.size() + 1 == smallHeap.size(), need balance
            // or largeHeap.size() == smallHeap.size() + 1,

            // 2. largeHeap.size() == smallHeap.size() + 1:
            // either largeHeap.size() == smallHeap.size(),
            // or largeHeap.size() == smallHeap.size() + 2, need balance
            tryBalance();
        }
    }

    private void tryBalance() {
        if (largeHeap.size() + 1 == smallHeap.size()) {
            // move from small to large
            largeHeap.offer(smallHeap.poll());
            // largeHeap.size() == smallHeap.size() + 1
        } else if (largeHeap.size() == smallHeap.size() + 2) {
            // move from large to small
            smallHeap.offer(largeHeap.poll());
            // largeHeap.size() == smallHeap.size() + 1
        }
    }

    public double findMedian() {
        if (largeHeap.isEmpty()) { // smallHeap must be empty as well
            return 0.0;
        } else if (largeHeap.size() == smallHeap.size()) {
            // neither largeHeap nor smallHeap are empty
            return (largeHeap.peek() + smallHeap.peek()) / 2.0;
        } else { // largeHeap.size() == smallHeap.size() + 1
            return largeHeap.peek();
        }
    }

}
