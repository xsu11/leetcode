package com.xinsu;

import com.xinsu.util.Node;

import java.util.HashMap;
import java.util.Map;

/*
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the
 * cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 *
 * Example 1:
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 * Constraints:
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 104
 * 0 <= value <= 105
 * At most 2 * 105 calls will be made to get and put.
 */

public class Q146_LRUCache {

    private final int capacity;
    private final Map<Integer, Node> cache = new HashMap<>();

    // dummy.next points to head that is the most recently used node
    // dummy.prev points to tail that is the least recently used node
    private final Node dummy = new Node();

    public Q146_LRUCache(int capacity) {
        this.capacity = capacity;
        this.dummy.prev = this.dummy;
        this.dummy.next = this.dummy;
    }

    public int get(int key) {
        final Node node = getNode(key);
        return node == null ? -1 : node.value;
    }

    public void put(int key, int value) {
        final Node node = getNode(key);
        if (node != null) {
            // found node, update
            node.value = value;
            return;
        }

        if (this.cache.size() == this.capacity) {
            // meet capacity, need to remove least recently used node
            final Node lruNode = this.dummy.prev;
            this.cache.remove(lruNode.key);
            removeNode(lruNode);
        }

        // node not found, insert node to the head
        final Node newNode = new Node(key, value);
        this.cache.put(key, newNode);
        putNodeHead(newNode);
    }

    private Node getNode(int key) {
        if (!this.cache.containsKey(key)) {
            return null;
        }

        final Node node = this.cache.get(key);

        // remove node then put node to the head
        removeNode(node);
        putNodeHead(node);

        return node;
    }

    private void putNodeHead(Node node) {
        node.next = this.dummy.next;
        node.prev = this.dummy;
        node.next.prev = node;
        node.prev.next = node;
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

}
