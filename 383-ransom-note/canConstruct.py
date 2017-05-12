#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# from collections import Counter
import collections

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        count = collections.Counter(magazine)
        for c in ransomNote:
            count[c] -= 1
            if count[c] < 0:
                return False
        return True

s = Solution()
print(s.canConstruct("aa", "aab"))
