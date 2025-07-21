package com.xinsu;

import com.xinsu.util.TrieNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Q336_PalindromePairs {

    private final TrieNode trie = new TrieNode();
    private final TrieNode reversedTrie = new TrieNode();
    // all lengths of words
    private final Set<Integer> wordLengthSet = new HashSet<>();
    // for each node in trie and reversed trie, save all word
    private final Map<TrieNode, List<Integer>> wordNodeMap = new HashMap<>();

    public List<List<Integer>> palindromePairs(String[] words) {
        // collect all input words length
        collectWordLength(words);

        final boolean[] selfPalindrome = new boolean[words.length]; // all non-empty self palindrome word pos
        int emptyWordIndex = -1; // empty string word

        for (int i = 0; i < words.length; i++) {
            // insert word into trie and reversed trie if it is non-empty
            if (!"".equals(words[i])) {
                insertWord(words, i);
            }

            // if the word is self palindrome, save its pos
            if (isPalindrome(words[i])) {
                if ("".equals(words[i])) {
                    emptyWordIndex = i;
                } else {
                    selfPalindrome[i] = true;
                }
            }
        }

        final List<List<Integer>> result = new ArrayList<>();

        // deal with empty word separately
        // if words contain empty string, concat it with every self palindrome word, then add to result
        if (emptyWordIndex != -1) {
            findPalindromeWithEmptyWord(emptyWordIndex, selfPalindrome, result);
        }

        // for all non-empty word, find all concatenated palindromes using DFS
        findPalindrome(this.trie, this.reversedTrie, words, result);

        return result;
    }

    private void collectWordLength(String[] words) {
        for (String word : words) {
            this.wordLengthSet.add(word.length());
        }
    }

    private void insertWord(String[] words, int wordIndex) {
        // create trie for all non-empty words
        // reverse all non-empty words then create reversed Trie
        TrieNode current = this.trie;
        TrieNode reversedCurrent = this.reversedTrie;
        final char[] wordC = words[wordIndex].toCharArray();
        for (int i = 0; i < wordC.length; i++) {
            current = current.insertChild(wordC[i]);
            reversedCurrent = reversedCurrent.insertChild(wordC[wordC.length - 1 - i]);

            /*
             * if there are other words that has the same length as current length on the path of this word, save this
             * current node as pass-through node of this word
             *
             * a node can be multiple words pass-through node
             */
            if (this.wordLengthSet.contains(i)) {
                addPassThroughNode(current, wordIndex);
                addPassThroughNode(reversedCurrent, wordIndex);
            }
        }

        current.setWord(true);
        current.setInfo(wordIndex);
        reversedCurrent.setWord(true);
        reversedCurrent.setInfo(wordIndex);
    }

    private void addPassThroughNode(TrieNode node, int wordIndex) {
        final List<Integer> wordIndexList = this.wordNodeMap.getOrDefault(node, new ArrayList<>());
        wordIndexList.add(wordIndex);
        this.wordNodeMap.put(node, wordIndexList);
    }

    private boolean isPalindrome(String word) {
        return isPalindrome(word, 0, word.length() - 1);
    }

    private boolean isPalindrome(String word, int begin, int end) {
        int left = begin;
        int right = end;
        final char[] wordC = word.toCharArray();
        while (left < right) {
            if (wordC[left++] != wordC[right++]) {
                return false;
            }
        }

        return true;
    }

    private static void findPalindromeWithEmptyWord(
            int emptyWordIndex,
            boolean[] selfPalindrome,
            List<List<Integer>> result) {
        for (int i = 0; i < selfPalindrome.length; i++) {
            if (selfPalindrome[i]) {
                result.add(Arrays.asList(i, emptyWordIndex));
                result.add(Arrays.asList(emptyWordIndex, i));
            }
        }
    }

    private void findPalindrome(
            TrieNode trie,
            TrieNode reversedTrie,
            String[] words,
            List<List<Integer>> result) {
        if (trie.isWord() && this.wordNodeMap.containsKey(reversedTrie)) {
            // trie node is a word
            final int info = trie.getInfo();
            // search in reversed trie for all words that has this reversed node as pass-through node
            for (final int i : this.wordNodeMap.get(reversedTrie)) {
                if (i != info
                        && isPalindrome(words[i], 0, words[i].length() - words[info].length() - 1)) {
                    result.add(Arrays.asList(info, i));
                }
            }
        }

        if (reversedTrie.isWord() && this.wordNodeMap.containsKey(trie)) {
            // reversed trie is a word
            final int reversedInfo = reversedTrie.getInfo();
            // search in trie for all words that has this node as pass-through node
            for (final int i : this.wordNodeMap.get(trie)) {
                if (i != reversedInfo
                        && isPalindrome(words[i], words[reversedInfo].length(), words[i].length() - 1)) {
                    result.add(Arrays.asList(reversedInfo, i));
                }
            }
        }

        final TrieNode[] children = trie.getChildren();
        for (int i = 0; i < children.length; i++) {
            final TrieNode child = children[i];
            if (child != null) {
                char c = (char) ('a' + i);
                if (reversedTrie.isChildExist(c)) {
                    findPalindrome(child, reversedTrie.getChild(c), words, result);
                }
            }
        }
    }

}
