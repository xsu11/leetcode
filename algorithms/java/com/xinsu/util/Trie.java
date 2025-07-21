package com.xinsu.util;

public class Trie {

    private final TrieNode root = new TrieNode();

    public Trie() {
    }

    public static Trie createTrie(String word) {
        final Trie trie = new Trie();
        trie.insert(word);
        return trie;
    }

    public TrieNode insert(String word) {
        TrieNode current = this.root;
        for (final char c : word.toCharArray()) {
            current = current.insertChild(c);
        }

        // current points to the leaf node of word
        current.setWord(true);
        return current;
    }

    public TrieNode insertWithInfo(String word, int info) {
        TrieNode current = insert(word);
        current.setInfo(info);
        return current;
    }

    public boolean search(String word) {
        final TrieNode current = searchWord(word);
        return current != null && current.isWord();
    }

    public boolean startsWith(String prefix) {
        // current either points to the leaf node of prefix or is null,
        // if current is not null, no matter whether leaf is word, prefix exists
        return searchWord(prefix) != null;
    }

    private TrieNode searchWord(String word) {
        return this.root.searchWord(word);
    }

    public TrieNode getRoot() {
        return this.root;
    }

}
