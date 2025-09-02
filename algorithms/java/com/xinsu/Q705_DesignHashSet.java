package com.xinsu;

import java.util.LinkedList;

/**
 * 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。
 *
 * 实现 MyHashSet 类：
 *
 * void add(key) 向哈希集合中插入值 key 。
 * bool contains(key) 返回哈希集合中是否存在这个值 key 。
 * void remove(key) 将给定值 key 从哈希集合中删除。如果哈希集合中没有这个值，什么也不做。
 *
 * 示例：
 *
 * 输入：
 * ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
 * [[], [1], [2], [1], [3], [2], [2], [2], [2]]
 * 输出：
 * [null, null, null, true, false, null, true, null, false]
 *
 * 解释：
 * MyHashSet myHashSet = new MyHashSet();
 * myHashSet.add(1);      // set = [1]
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(1); // 返回 True
 * myHashSet.contains(3); // 返回 False ，（未找到）
 * myHashSet.add(2);      // set = [1, 2]
 * myHashSet.contains(2); // 返回 True
 * myHashSet.remove(2);   // set = [1]
 * myHashSet.contains(2); // 返回 False ，（已移除）
 *
 *
 * 提示：
 *
 * 0 <= key <= 106
 * 最多调用 104 次 add、remove 和 contains
 */
public class Q705_DesignHashSet {

    public static class MyHashSet {

        private static final int BASE = 769;

        private final LinkedList[] data;

        public MyHashSet() {
            this.data = new LinkedList[BASE];
            for (int i = 0; i < BASE; i++) {
                this.data[i] = new LinkedList<Integer>();
            }
        }

        public void add(int key) {
            final int h = hash(key);
            if (data[h].contains(key)) {
                return;
            }

            data[h].offerLast(key);
        }

        public void remove(int key) {
            final int h = hash(key);
            if (!data[h].contains(key)) {
                return;
            }

            data[h].remove(Integer.valueOf(key));
        }

        public boolean contains(int key) {
            final int h = hash(key);
            return data[h].contains(key);
        }

        private int hash(int key) {
            return key % BASE;
        }

    }

}
