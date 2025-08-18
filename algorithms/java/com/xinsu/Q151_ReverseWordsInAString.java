package com.xinsu;

/**
 * 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
 *
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 *
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 *
 * 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，
 * 且不包含任何额外的空格。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 * 示例 2：
 *
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：反转后的字符串中不能存在前导空格和尾随空格。
 * 示例 3：
 *
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
 *
 *
 * 提示：
 *
 * 1 <= s.length <= 104
 * s 包含英文大小写字母、数字和空格 ' '
 * s 中 至少存在一个 单词
 */
public class Q151_ReverseWordsInAString {

    public String reverseWords(String s) {
        final StringBuilder sb = trimString(s);
        reverseString(sb, 0, sb.length() - 1);
        reverseWord(sb);
        return sb.toString();
    }

    private StringBuilder trimString(String s) {
        // skip prefix whitespaces
        int left = 0;
        while (left < s.length() && s.charAt(left) == ' ') {
            left++;
        }

        // skip all suffix whitespaces
        int right = s.length() - 1;
        while (left < right + 1 && s.charAt(right) == ' ') {
            right--;
        }

        // invariant:
        // 1. left points to the first non-empty char of the string
        // 2. right points to the last non-empty char of the string
        final StringBuilder sb = new StringBuilder();
        while (left < right + 1) {
            if (left == 0) {
                if (s.charAt(left) != ' ') {
                    sb.append(s.charAt(left));
                }
            } else {
                if (s.charAt(left) != ' ' || s.charAt(left - 1) != ' ') {
                    sb.append(s.charAt(left));
                }
            }

            left++;
        }

        return sb;
    }

    private void reverseString(StringBuilder sb, int begin, int end) {
        while (begin < end) {
            final char tmp = sb.charAt(begin);
            sb.setCharAt(begin, sb.charAt(end));
            sb.setCharAt(end, tmp);

            begin++;
            end--;
        }
    }

    private void reverseWord(StringBuilder sb) {
        // use two pointers, initially pointing to the first non-empty char of the first word
        int left = 0;
        int right = 0;

        // invariant: left points to a word's beginning
        while (left < sb.length()) {
            while (right < sb.length() && sb.charAt(right) != ' ') {
                right++;
            }

            // end reaches to the end of the string, or to the whitespace between two words
            reverseString(sb, left, right - 1);

            // update left to the first char of next word
            left = right + 1;
            right = left;
        }
    }

}
