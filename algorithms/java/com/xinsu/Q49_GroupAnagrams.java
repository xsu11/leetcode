package com.xinsu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
 *
 *
 *
 * 示例 1:
 *
 * 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
 *
 * 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * 解释：
 *
 * 在 strs 中没有字符串可以通过重新排列来形成 "bat"。
 * 字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。
 * 示例 2:
 *
 * 输入: strs = [""]
 *
 * 输出: [[""]]
 *
 * 示例 3:
 *
 * 输入: strs = ["a"]
 *
 * 输出: [["a"]]
 *
 *
 *
 * 提示：
 *
 * 1 <= strs.length <= 104
 * 0 <= strs[i].length <= 100
 * strs[i] 仅包含小写字母
 */

public class Q49_GroupAnagrams {

    public List<List<String>> groupAnagrams(String[] strs) {
        final Map<String, List<String>> map = solve(strs);
        return check(map);
    }

    private Map<String, List<String>> solve(String[] strs) {
        final Map<String, List<String>> map = new HashMap<>();
        for (final String str : strs) {
            final String key = createStringCountKey(str);
            final List<String> value = map.getOrDefault(key, new ArrayList<>());
            value.add(str);
            map.put(key, value);
        }

        return map;
    }

    private static String createStringCountKey(String str) {
        final int[] counts = new int[26];
        for (final char c : str.toCharArray()) {
            counts[c - 'a']++;
        }

        final StringBuilder sb = new StringBuilder();
        for (int i = 0; i < counts.length; i++) {
            if (counts[i] != 0) {
                sb.append((char) (i + 'a')).append(counts[i]);
            }
        }

        return sb.toString();
    }

    private List<List<String>> check(Map<String, List<String>> map) {
        return new ArrayList<>(map.values());
    }

}
