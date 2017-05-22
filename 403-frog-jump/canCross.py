# 总是超时，无法理解。。。
class Solution(object):
    def canCross(self, stones):
        """
        :type stones: List[int]
        :rtype: bool
        """
        if stones[1] != 1: return False
        n = len(stones)
        kMax = 1
        dp = [set() for x in range(n)]
        dp[1].add(1);
        for i in range(n):
            if stones[i] - stones[i - 1] > kMax + 1: return False
            for k in dp[i]:
                for j in range(i + 1, n):
                    units = stones[j] - stones[i]
                    if units > k + 1: break
                    elif units >= k - 1:
                        kMax = max(kMax, units)
                        dp[j].add(units)
        return len(dp[-1]) > 0

s = Solution()
print(s.canCross([0,1,8753,13918,15296,18937,21862,24163,27446,28035,30408,30993,32241,33268,39429,40743,50325,51872]))

# 0,1,3,4,5,7,8,9,11,12,13,15,16,17,19,20,21,23,24,25,27,28,29,31,32,33,35,36,37,39,40,41,43,44,45,47,48
