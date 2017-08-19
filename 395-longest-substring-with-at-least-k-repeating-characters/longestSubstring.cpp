/**
    找到最长的子串，使得子串的每个字符的出现次数 >= k
    递归解，虽然能A，但是效率有点低
*/
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (k <= 1) return s.size();

        unordered_map<char, int> myMap;

        for (char c : s) myMap[c]++;

        int n = s.size(), ret = 0, cur = 0, i = 0;

        for (i = 0; i < n; i++) {
            if (myMap[s[i]] < k) break;
        }

        if (i == n) return s.size();

        ret = max(longestSubstring(s.substr(0, i), k), longestSubstring(s.substr(i + 1), k));

        return ret;
    }
};

// 待完善。。http://www.cnblogs.com/grandyang/p/5852352.html
