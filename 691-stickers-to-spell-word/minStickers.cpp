/**
    WA1:
    ["travel","quotient","nose","wrote"]
    "lastwest"
    WA2:
    ["soil","since","are","put"]
    "appearreason"
    WA3:
    ["neighbor","capital"]
    "originalchair"
*/

// TLE， 加了那个优化点还WA，较复杂，弃
class Solution {
public:
    int help(vector<map<char, int>> stickersMap, map<char, int> targetMap, int start,
             int n, vector<map<map<char, int>, int>> dp) {

        if (targetMap.empty()) return 0;
        if (start == n) return -1;

        if (dp[start].find(targetMap) != dp[start].end()) return dp[start][targetMap];

        int ret = -1;

        for (int i = 0; i < n; i++) {
            // 优化点
            if (stickersMap[i].find(targetMap.begin()->first) == stickersMap[i].end()) continue;

            map<char, int> stickerTmp = stickersMap[i];
            map<char, int> targetTmp = targetMap;
            int num = 0;

            vector<char> toDel;
            for (auto it : targetTmp) {
                char c = it.first;
                if (stickerTmp.find(c) != stickerTmp.end()) {
                    toDel.push_back(c);
                    num = max(num, (targetTmp[c] + stickerTmp[c] - 1) / stickerTmp[c]);
                }
            }

            for (int j = 1; j <= num; j++) {
                map<char, int> tmpMap = targetTmp;
                for (char c : toDel) {
                    tmpMap[c] -= j * stickerTmp[c];
                    if (tmpMap[c] <= 0) tmpMap.erase(c);
                }

                int tmpRet = help(stickersMap, tmpMap, i + 1, n, dp);
                if (tmpRet != -1) {
                    if (ret == -1) ret = j + tmpRet;
                    else ret = min(ret, j + tmpRet);
                }
            }
        }
        return dp[start][targetMap] = ret;
    }
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();

        map<char, int> targetMap;
        vector<map<char, int>> stickersMap(n);
        vector<map<map<char, int>, int>> dp(n);

        for (char c : target) targetMap[c]++;
         for (int i = 0; i < n; i++) {
            for (char c : stickers[i]) {
                if (targetMap.find(c) != targetMap.end()) {
                    stickersMap[i][c]++;
                }
            }
        }

        return help(stickersMap, targetMap, 0, n, dp);
    }
};

/**
    参考：https://discuss.leetcode.com/topic/106273/c-java-python-dp-memoization-with-optimization-29-ms-c
    改变思路，题目要求的target长度最长只有15，可以直接从target入手。
    而上面自己的超时解法主要是从stickers入手遍历。。

    两个优化点：
    1. dp数组
    2. target[0]
*/

// 搞不懂。。参考上述discuss写了以下解法还超时，map的访问比vector更慢？？？
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<map<char, int>> stickersMap(m);
        unordered_map<string, int> dp;

        for (int i = 0; i < m; i++)
            for (char c : stickers[i])
                stickersMap[i][c]++;
        dp[""] = 0;
        return helper(dp, stickersMap, target);
    }
private:
    int helper(unordered_map<string, int>& dp, vector<map<char, int>> stickersMap, string target) {
        if (dp.count(target)) return dp[target];

        int ans = INT_MAX, n = stickersMap.size();

        map<char, int> targetMap;
        for (char c : target) targetMap[c]++;
        for (int i = 0; i < n; i++) {
            if (stickersMap[i][target[0]] == 0) continue;

            string s;
            for (auto it : targetMap) {
                char c = it.first;
                if (targetMap[c] - stickersMap[i][c] > 0) s += string(targetMap[c] - stickersMap[i][c], c);
            }

            if (s.size() != target.size()) {
                int tmp = helper(dp, stickersMap, s);
                if (tmp != -1) ans = min(ans, 1 + tmp);
            }
        }
        dp[target] = ans == INT_MAX? -1:ans;
        return dp[target];
    }
};
