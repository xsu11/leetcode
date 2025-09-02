package com.xinsu;

/**
 * Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。
 * 这一数据结构有相当多的应用情景，例如自动补全和拼写检查。
 *
 * 请你实现 Trie 类：
 *
 * Trie() 初始化前缀树对象。
 * void insert(String word) 向前缀树中插入字符串 word 。
 * boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
 * boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。
 *
 *
 * 示例：
 *
 * 输入
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * 输出
 * [null, null, true, false, true, null, true]
 *
 * 解释
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // 返回 True
 * trie.search("app");     // 返回 False
 * trie.startsWith("app"); // 返回 True
 * trie.insert("app");
 * trie.search("app");     // 返回 True
 *
 *
 * 提示：
 *
 * 1 <= word.length, prefix.length <= 2000
 * word 和 prefix 仅由小写英文字母组成
 * insert、search 和 startsWith 调用次数 总计 不超过 3 * 104 次
 */
public class Q208_ImplementTrie_PrefixTree {

    public class Trie {

        private final Trie[] children = new Trie[26];
        private boolean leaf = false;

        public Trie() {
        }

        public void insert(String word) {
            Trie cur = this;
            final char[] wordC = word.toCharArray();
            for (final char c : wordC) {
                final int i = c - 'a';
                if (cur.getChild(i) == null) {
                    cur.setChild(i);

                }

                // cur move to next level
                cur = cur.getChild(i);
            }

            // cur is at leaf
            cur.setLeaf(true);

        }

        public boolean search(String word) {
            Trie node = searchString(word);
            return node != null && node.isLeaf();
        }

        public boolean startsWith(String prefix) {
            Trie node = searchString(prefix);
            return node != null;
        }

        private Trie searchString(String s) {
            Trie cur = this;
            final char[] sc = s.toCharArray();
            for (final int c : sc) {
                final int i = c - 'a';
                if (cur.getChild(i) == null) {
                    // not found
                    return null;
                }

                // cur move to next level
                cur = cur.getChild(i);
            }

            // found
            return cur;
        }

        public void setChild(int i) {
            this.children[i] = new Trie();
        }

        public Trie getChild(int i) {
            return this.children[i];
        }

        public void setLeaf(boolean leaf) {
            this.leaf = leaf;
        }

        public boolean isLeaf() {
            return this.leaf;
        }

    }

}
