package com.xinsu;

import java.util.PriorityQueue;

public class Q295_FindMedianFromDataStream {

    private PriorityQueue<Integer> largeHeap = new PriorityQueue<>((a, b) -> a - b); // min heap by default
    private PriorityQueue<Integer> smallHeap = new PriorityQueue<>((a, b) -> b - a); // max heap

    public Q295_FindMedianFromDataStream() {
    }

    public void addNum(int num) {
        // boundary case
        if (largeHeap.isEmpty()) { // smallHeap must be empty as well
            largeHeap.offer(num);
        } else {
            // either largeHeap.size() == smallHeap.size(),
            // or largeHeap.size() == smallHeap.size() + 1
            if (largeHeap.peek() < num) {
                largeHeap.offer(num);
            } else {
                smallHeap.offer(num);
            }

            // largeHeap.size() == smallHeap.size():
            // either largeHeap.size() + 1 == smallHeap.size(), need balance
            // or largeHeap.size() == smallHeap.size() + 1,

            // largeHeap.size() == smallHeap.size() + 1:
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
