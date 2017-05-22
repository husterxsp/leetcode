#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from collections import defaultdict

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        myDict = defaultdict(lambda: 0)
        for c in s:
            myDict[c] += 1
        for i, c in enumerate(s):
            if myDict[s[i]] == 1:
                return i
        return -1

s = Solution()
print(s.firstUniqChar("leetcode"))
