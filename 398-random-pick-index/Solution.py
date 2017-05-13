#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random

class Solution(object):

    def __init__(self, nums):
        """

        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        i = 0;
        ret = 0;

        p = 0;
        n = len(self.nums);
        while p < n:
            if self.nums[p] == target:
                choice = random.randint(0, i);
                if choice == 0:
                    ret = p;
                i += 1
            p += 1;
        return ret;

obj = Solution([1, 2, 3, 3, 3])
i = 1
while i < 1000:
    i += 1
    print(obj.pick(3))
