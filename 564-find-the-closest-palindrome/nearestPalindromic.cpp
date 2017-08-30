/**
    总体思路比较清晰。。但是需要注意各种边界情况
    参考：http://www.cnblogs.com/weedboy/p/6848662.html

*/
class Solution {
public:
    string other(string s, int l) {
        if (l % 2 == 1) s = s.substr(0, s.size() - 1);
        reverse(s.begin(), s.end());
        return s;
    }
    string nearestPalindromic(string n) {
        int l = n.size();
        set<long> candidates;

        long mid = stol(n.substr(0, (l + 1) / 2));

        candidates.insert(long(pow(10, l)) + 1);
        candidates.insert(long(pow(10, l - 1) - 1));

        for (int i = -1; i <= 1; i++) {
            string s = to_string(mid + i);
            string ss = s + other(s, l);
            candidates.insert(stol(ss));
        }

        long num = stol(n), minDiff = LONG_MAX, diff, minVal = LONG_MAX;
        candidates.erase(num);
        for (long v : candidates) {
            diff = abs(v - num);

            if (diff < minDiff) {
                minVal = v;
                minDiff = diff;
            }
            else if (diff == minDiff) {
                minVal = min(minVal, v);
            }
        }
        return to_string(minVal);
    }
};
