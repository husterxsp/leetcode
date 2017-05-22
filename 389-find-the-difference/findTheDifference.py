#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import defaultdict
class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        myDict = defaultdict(lambda: 0)
        for c in s:
            myDict[c] -= 1
        for c in t:
            myDict[c] += 1
            if myDict[c] == 1:
                return c
        return 0

s = Solution()
print(s.findTheDifference('abcd', 'abcde'))
