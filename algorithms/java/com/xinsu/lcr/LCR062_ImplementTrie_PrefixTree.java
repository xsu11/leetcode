package com.xinsu.lcr;

import com.xinsu.util.TrieNode;

public class LCR062_ImplementTrie_PrefixTree {

    private final TrieNode root = new TrieNode();

    public LCR062_ImplementTrie_PrefixTree() {
    }

    public void insert(String word) {
        TrieNode current = this.root;
        for (final char c : word.toCharArray()) {
            if (!current.isChildExist(c)) {
                current.createChild(c);
            }

            current = current.getChild(c);
        }

        // current points to the leaf node of word
        current.setWord(true);

    }

    public boolean search(String word) {
        final TrieNode current = searchNode(word);
        return current != null && current.isWord();
    }

    public boolean startsWith(String prefix) {
        // current either points to the leaf node of prefix or is null,
        // if current is not null, no matter whether leaf is word, prefix exists
        return searchNode(prefix) != null;
    }

    private TrieNode searchNode(String word) {
        TrieNode current = this.root;
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
