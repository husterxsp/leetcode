/*
    不会。。
    思路：暴力搜索+map保存数据，如果不用map的话总的时间复杂度 n!, 即全排列
    如果用 vector<int> vis(maxChoosableInteger + 1); 来表示某个数是否访问过应该也可以，
    但这样就需要定义unordered_map<vector<int>, bool> m; 这样的map函数，还需要自定义hash函数
    所以用一个整数来代替vis数组，会方便很多
*/
class Solution {
public:
    bool help(int maxChoosableInteger, int total, int vis, unordered_map<int, bool>& myMap) {
        if (myMap.find(vis) != myMap.end()) return myMap[vis];
        for (int i = 1; i <= maxChoosableInteger; i++) {
            int cur = 1 << i;
            // &操作符优先级比较低，记得加括号
            if ((cur & vis) == 0) {
                if (total <= i || !help(maxChoosableInteger, total - i, cur | vis, myMap)) {
                    return myMap[vis] = true;
                }
            }
        }
        return myMap[vis] = false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;

        unordered_map<int, bool> myMap;

        return help(maxChoosableInteger, desiredTotal, 0, myMap);
    }
};
