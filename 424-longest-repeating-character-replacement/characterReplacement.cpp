/**
    没头绪。。
    参考：http://www.cnblogs.com/grandyang/p/5999050.html
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> myMap;
        int ret = 0, start = 0, maxCnt = 0;
        for (int i = 0; i < s.size(); i++) {
            myMap[s[i]]++;
            maxCnt = max(maxCnt, myMap[s[i]]);
            while (i - start + 1 - maxCnt > k) {
                myMap[s[start]]--;
                start++;
            }
            ret = max(ret, i - start + 1);
        }
        return ret;
    }
};
