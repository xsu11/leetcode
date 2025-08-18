package com.xinsu;

import java.util.PriorityQueue;

public class Q295_FindMedianFromDataStream {

    private final PriorityQueue<Integer> largeHeap = new PriorityQueue<>();
    private final PriorityQueue<Integer> smallHeap = new PriorityQueue<>((a, b) -> b - a);

    public Q295_FindMedianFromDataStream() {

    }

    public void addNum(int num) {
        // large size == small size, or
        // large size == small size + 1

        if (largeHeap.isEmpty() || largeHeap.peek() <= num) {
            // insert into large heep
            largeHeap.offer(num);
        } else if (smallHeap.isEmpty() || num <= smallHeap.peek()) {
            // insert into small heap
            smallHeap.offer(num);
        } else { // smallHeap.peek() < num && num < largeHeap.peek()
            // decide based on size
            if (largeHeap.size() == smallHeap.size()) {
                // insert into large heep
                largeHeap.offer(num);
            } else { // largeHeap.size() == smallHeap.size() + 1
                // insert into small heap
                smallHeap.offer(num);
            }
        }

        // large size == small size ->
        // large == small + 1, no need to do balance
        // large + 1 = small

        // large size == small size + 1 ->
        // large == small, no need to do balance
        // large == small + 2

        if (largeHeap.size() < smallHeap.size()) {
            // large + 1 = small
            // move small to large
            largeHeap.offer(smallHeap.poll());
            // large == small + 1
        } else if (largeHeap.size() > smallHeap.size() + 1) {
            // large == small + 2
            // move large to small
            smallHeap.offer(largeHeap.poll());
            // large == small
        }
    }

    public double findMedian() {
        if (largeHeap.isEmpty() && smallHeap.isEmpty()) {
            return 0.0;
        } else if (smallHeap.isEmpty()) { // !largeHeap.isEmpty()
            return largeHeap.peek();
        } else if (largeHeap.size() == smallHeap.size()) {
            return (smallHeap.peek() + largeHeap.peek()) / 2.0;
        } else { // largeHeap.size() == smallHeap.size() + 1
            return largeHeap.peek();
        }
    }

}
