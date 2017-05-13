#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import math

class Solution(object):
    def constructRectangle(self, area):
        """
        :type area: int
        :rtype: List[int]
        """
        i = int(math.sqrt(area))
        while i > 0:
            if area % i != 0:
                i -= 1
                continue
            return [int(area / i), i]

s = Solution()
print(s.constructRectangle(1))
