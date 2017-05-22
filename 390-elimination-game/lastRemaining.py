class Solution(object):
    def lastRemaining(self, n):
        """
        :type n: int
        :rtype: int
        """
        k = 1
        gap = 1
        ret = 1
        while n > 1:
            flag = 1 if k % 2 else -1

            n /= 2
            ret = ret + flag * (gap + 2 * gap * (n - 1))

            k += 1
            gap *= 2
        return ret

s = Solution()
print(s.lastRemaining(9))
