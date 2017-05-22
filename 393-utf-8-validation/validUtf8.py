#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def validUtf8(self, data):
        """
        :type data: List[int]
        :rtype: bool
        """
        n = len(data)
        if n == 0: return True

        bytes = 0
        for i, val in enumerate(data):
            if bytes > 0:
                if val & 192 != 128: return False
                bytes -= 1
            elif val & 128 != 0:
                if val & 64 == 0: return False
                while val & 128 != 0:
                    bytes += 1
                    val <<= 1
                if bytes > 4: return False
                bytes -= 1
        return bytes == 0

s = Solution()
print(s.validUtf8([235, 140, 4]))
