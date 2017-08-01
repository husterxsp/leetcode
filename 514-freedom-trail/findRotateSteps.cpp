class Solution {
public:
    /**
        思路：按照正负方向来考虑，pos表示当前转动后位于0点的位置
        findPositive：从0点往正方向找，第一个对应char的位置
        findNegative：从0点往负方向找，...

        这种解法超时。。时间复杂度差不多O(2^n)。。。
     */
     int findPositive(string ring, int pos, char c) {
         int n = ring.size(), i = pos;
         while (ring[i] != c) {
             i = (i + 1) % n;
         }
         return i;
     }
     int findNegative(string ring, int pos, char c) {
         int n = ring.size(), i = pos;
         while (ring[i] != c) {
             i--;
             if (i < 0) i = n - 1;
         }
         return i;
     }

     int search(string ring, int pos, string key) {
         int l1 = ring.size(), l2 = key.size();
         if (l2 == 0) return 0;

         int firstPositive = findPositive(ring, pos, key[0]);
         int firstNegative = findNegative(ring, pos, key[0]);
         int positiveDis = firstPositive - pos;
         int negativeDis = pos - firstNegative;

         if (positiveDis < 0) positiveDis += l1;
         if (negativeDis < 0) negativeDis += l1;

         if (l2 == 1) return min(positiveDis, negativeDis);

         if (firstPositive == firstNegative) {
             return min(positiveDis, negativeDis) + search(ring, firstPositive, key.substr(1));
         }

         int searchPositive = search(ring, firstPositive, key.substr(1)) + positiveDis;
         int searchNegative = search(ring, firstNegative, key.substr(1)) + negativeDis;

         return min(searchPositive, searchNegative);
     }
     int findRotateSteps(string ring, string key) {
         int s = search(ring, 0, key);
         return s + key.size();
     }
};
/**
    解2：动态规划，设一个二维数组dp
    dp[i][j]表示当前ring的12点位置是ring[j]，那么key.substr(i) 需要的转动次数
    时间复杂度 O(n^3)
*/
/**
    一个感觉，动规可以省略掉一些情况不需要特别考虑，
    如ring中有重复的话，上面的超时解法还去一个个找对应的的正方向和负方向的char
    动规还是简单好多。。关键是得想出递推公式啊啊。。。
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(m + 1, vector<int>(n));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    if (ring[k] == key[i]) {
                        int dis = abs(k - j);
                        // 因为当前key[i] 对应的ring转动到了k位置，所以下一个key[i + 1] 对应的ring就在k位置
                        // 所以 + dp[i + 1][k]
                        dp[i][j] = min(dp[i][j], min(dis, n - dis) + dp[i + 1][k]);
                    }
                }
            }
        }
        return dp[0][0] + m;
    }
};
