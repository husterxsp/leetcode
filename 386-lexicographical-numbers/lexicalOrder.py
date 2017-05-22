#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ret = [1]
        cur = 1
        while len(ret) < n:
            while cur <= n / 10:
                cur *= 10
                ret.append(cur)
            cur += 1
            while cur % 10 == 0:
                cur /= 10
            if cur <= n:
                ret.append(cur)
        return ret

s = Solution()
print(s.lexicalOrder(19))
