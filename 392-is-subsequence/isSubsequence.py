#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        sn = len(s)
        tn = len(t)
        if sn == 0: return True

        si = 0
        ti = 0
        while ti < tn:
            if t[ti] == s[si]: si += 1
            if si == sn: return True
            ti += 1
        return False;

s = Solution()
print(s.isSubsequence("abc", "axbvc"))
