package com.xinsu;

import com.xinsu.util.Node;

import java.util.HashMap;
import java.util.Map;

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
