package com.xinsu;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.util.function.IntConsumer;

/**
 * 现有函数 printNumber 可以用一个整数参数调用，并输出该整数到控制台。
 *
 * 例如，调用 printNumber(7) 将会输出 7 到控制台。
 * 给你类 ZeroEvenOdd 的一个实例，该类中有三个函数：zero、even 和 odd 。ZeroEvenOdd 的相同实例将会传递给三个不同线程：
 *
 * 线程 A：调用 zero() ，只输出 0
 * 线程 B：调用 even() ，只输出偶数
 * 线程 C：调用 odd() ，只输出奇数
 * 修改给出的类，以输出序列 "010203040506..." ，其中序列的长度必须为 2n 。
 *
 * 实现 ZeroEvenOdd 类：
 *
 * ZeroEvenOdd(int n) 用数字 n 初始化对象，表示需要输出的数。
 * void zero(printNumber) 调用 printNumber 以输出一个 0 。
 * void even(printNumber) 调用printNumber 以输出偶数。
 * void odd(printNumber) 调用 printNumber 以输出奇数。
 *
 *
 * 示例 1：
 *
 * 输入：n = 2
 * 输出："0102"
 * 解释：三条线程异步执行，其中一个调用 zero()，另一个线程调用 even()，最后一个线程调用odd()。正确的输出为 "0102"。
 * 示例 2：
 *
 * 输入：n = 5
 * 输出："0102030405"
 *
 *
 * 提示：
 *
 * 1 <= n <= 1000
 */
public class Q1116_PrintZeroEvenOdd_ReentrantLock_I {

    /**
     * ReentrantLock is used as lock
     * three separate Conditions(await/signal) are used as barrier
     */

    public static class ZeroEvenOdd {

        private final int n;
        private final ReentrantLock lock = new ReentrantLock();
        private final Condition[] condition = new Condition[3];
        /**
         * 0->print 0
         * 1->print 1
         * 2->print 0
         * 3->print 2
         */
        private volatile int flag = 0;

        public ZeroEvenOdd(int n) {
            this.n = n;
            for (int i = 0; i < this.condition.length; i++) {
                this.condition[i] = this.lock.newCondition();
            }
        }

        // printNumber.accept(x) outputs "x", where x is an integer.
        public void zero(IntConsumer printNumber) throws InterruptedException {
            for (int i = 1; i < this.n + 1; i++) {
                this.lock.lock();
                try {
                    printNumber.accept(0);

                    this.flag = ++this.flag % 4; // 0->1 / 2->3

                    // then print even/odd based on i
                    if (this.flag == 1) {
                        // print odd
                        this.condition[1].signal();
                    } else if (this.flag == 3) {
                        // print even
                        this.condition[2].signal();
                    }

                    this.condition[0].await();
                } finally {
                    this.lock.unlock();
                }
            }
        }

        public void even(IntConsumer printNumber) throws InterruptedException {
            for (int i = 2; i < this.n + 1; i += 2) {
                this.lock.lock();
                try {
                    if (this.flag != 3) {
                        this.condition[2].await();
                    }
                    // got signal for printing even
                    printNumber.accept(i);

                    this.flag = ++this.flag % 4;
                    this.condition[0].signal();
                } finally {
                    this.lock.unlock();
                }
            }
        }

        public void odd(IntConsumer printNumber) throws InterruptedException {
            for (int i = 1; i < this.n + 1; i += 2) {
                this.lock.lock();
                try {
                    if (this.flag != 1) {
                        this.condition[1].await();
                    }
                    // got signal for printing odd
                    printNumber.accept(i);

                    this.flag = ++this.flag % 4;
                    this.condition[0].signal();
                } finally {
                    this.lock.unlock();
                }
            }
        }

    }

}
