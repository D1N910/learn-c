# 【每日编程-134期】：给定一个字符串，找出不含有重复字符的最长子串的长度。

示例 1:

输入: "abcabcbb"

输出: 3

解释:无重复字符的最长子串是"abc"，其长度为 3。

示例 2:

输入: "bbbbb"

输出: 1

解释: 无重复字符的最长子串是"b"，其长度为 1。

示例 3:

输入: "pwwkew"

输出: 3

解释: 无重复字符的最长子串是 "wke"，其长度为 3。

     请注意，答案必须是一个子串，"pwke" 是一个子序列而不是子串。

# from https://mp.weixin.qq.com/s/3O-mug4P1KnFVXMPNx2fdA


/**
 * @brief 
 * 从第二个开始遍历
 *      从现在字符串头往后检索，如果检索到有重复的
 *          如果(endIndex - startIndex) > (lendIndex - lStartIndex)
 *              那么同步lendIndex=endIndex;lStartIndex=startIndex;
 *          startIndex+1，endIndex+1
 *          如果(字符串长度 - 1) - startIndex 小于 endIndex - startIndex
 *          那么打断遍历
 * 如果检索到没有重复的，那么startIndex不变，endIndex+1
 * 遍历完毕
 * 如果(endIndex - startIndex) > (lendIndex - lStartIndex)
 * 那么同步lendIndex=endIndex;lStartIndex=startIndex;
 */