// 数学题，如何判断正方形？ https://zh.wikipedia.org/wiki/%E6%AD%A3%E6%96%B9%E5%BD%A2
// 解法1：边的长度只有两种
class Solution {
public:
    int dis(vector<int> a, vector<int> b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> mySet{dis(p1, p2), dis(p1, p3), dis(p1, p4), dis(p2, p3), dis(p2, p4), dis(p3, p4)};
        return !mySet.count(0) && mySet.size() == 2;
     }
};
