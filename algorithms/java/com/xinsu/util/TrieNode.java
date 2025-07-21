package com.xinsu.util;

public class TrieNode {

    private final TrieNode[] children = new TrieNode[26];
    private boolean word = false;
    private int info = -1;

    public TrieNode() {
    }

    public TrieNode(final boolean word) {
        this.word = word;
    }

    public boolean isWord() {
        return this.word;
    }

    public void setWord(boolean word) {
        this.word = word;
    }

    public int getInfo() {
        return this.info;
    }

    public void setInfo(int info) {
        this.info = info;
    }

    public TrieNode[] getChildren() {
        return this.children;
    }

    public TrieNode getChild(final char c) {
        return this.children[c - 'a'];
    }

    public boolean isChildExist(final char c) {
        return this.children[c - 'a'] != null;
    }

    public void createChild(final char c) {
        this.children[c - 'a'] = new TrieNode();
    }

    public TrieNode insertChild(char c) {
        if (!isChildExist(c)) {
            createChild(c);
        }

        return getChild(c);
    }

    public TrieNode searchWord(String word) {
        TrieNode current = this;
        for (final char c : word.toCharArray()) {
            if (!current.isChildExist(c)) {
                return null;
            }

            current = current.getChild(c);
        }

        // current points to the leaf node of word
        return current;
    }

}
