package com.xinsu;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
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
public class Q1116_PrintZeroEvenOdd_CyclicBarrier {

    /**
     * three separate CyclicBarrier(await() for two to arrive) are used as lock + barrier
     */

    private final int n;

    // zero barrier: wait on zero and even/odd to arrive at barrier
    private final CyclicBarrier zeroC = new CyclicBarrier(2);

    // even barrier: wait on even and zero to arrive at barrier
    private final CyclicBarrier evenC = new CyclicBarrier(2);

    // odd barrier: wait on odd and zero to arrive at barrier
    private final CyclicBarrier oddC = new CyclicBarrier(2);

    public Q1116_PrintZeroEvenOdd_CyclicBarrier(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i < this.n + 1; i++) {
            printNumber.accept(0);

            if (i % 2 == 0) {
                waitC(this.evenC); // zero arrived at even barrier to trigger printing even
            } else {
                waitC(this.oddC); // zero arrived at odd barrier to trigger printing odd
            }

            waitC(this.zeroC); // zero arrived at zero barrier, waiting for even/odd to arrive
            // both zero and even/odd have arrived, proceed to next loop
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i < this.n + 1; i += 2) {
            waitC(this.evenC); // even arrived at even barrier, wait for zero to arrive
            // both even and zero have arrived, proceed to print even
            printNumber.accept(i);
            waitC(this.zeroC); // even arrived at zero barrier to trigger printing zero
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i < this.n + 1; i += 2) {
            waitC(this.oddC); // odd arrived at odd barrier, wait for zero to arrive
            // both odd and zero have arrived, proceed to print odd
            printNumber.accept(i);
            waitC(this.zeroC); // odd arrived at zero barrier to trigger printing zero
        }
    }

    private void waitC(CyclicBarrier c) throws InterruptedException {
        try {
            c.await();
        } catch (InterruptedException | BrokenBarrierException e) {
            throw new InterruptedException(e.getMessage());
        }
    }

}
