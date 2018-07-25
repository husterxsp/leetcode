1. Two Sum
查找问题，hash
思路1：先排序再二分搜索，O(nlogn)
思路2：hash，O(n)

因为本题要求输出indice，所以先用map存储一下 (num[i], i)键值对。注意用的是unordered_map，无序map。如果直接用map的话
复杂度就也变成O(nlogn)。java 里面的话，应该用 HashMap而不是TreeMap

2. Add Two Numbers
思路：就是两个数相加，而且题目都给好了逆序的，连链表反转都不用做

3. Longest Substring Without Repeating Characters
第一反应是用map或者set, 但是需要知道在前面的字符串中重复出现的字符的位置，好让下一次搜索的起点为该位置+1，所以用map，但是效率不高，
两重循环。

```cpp
int lengthOfLongestSubstring(string s) {
    int ret = 0, start = 0;
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.size(); i++) {
        if (mymap.find(s[i]) != mymap.end()) {
            int pos = mymap[s[i]];
            for (int j = start; j <= pos; j++) mymap.erase(s[j]);
            start = pos + 1;
        }
        mymap[s[i]] = i;
        ret = max(ret, i - start + 1);
    }
    return ret;
}
```
优化：参考[discuss的解](https://leetcode.com/problems/longest-substring-without-repeating-characters/discuss/1729/11-line-simple-Java-solution-O(n)-with-explanation) ，其实不用删除

```cpp
int lengthOfLongestSubstring(string s) {
    int ret = 0, start = 0;
    unordered_map<char, int> mymap;
    for (int i = 0; i < s.size(); i++) {
        if (mymap.find(s[i]) != mymap.end()) {
            start = max(start, mymap[s[i]] + 1);
        }
        mymap[s[i]] = i;
        ret = max(ret, i - start + 1);
    }
    return ret;
}
```

4. Median of Two Sorted Arrays

要求时间复杂度是 O(log (m+n)) 那么就是得用二分。关键怎么分。
参考网上的解答，该题可以转化为求 两个数组中第K大的数。
