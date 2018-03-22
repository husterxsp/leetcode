#!/usr/bin/env python3
# -*- coding: utf-8 -*-

class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key = lambda row: (row[0], -row[1]))
        n = len(people)
        for i in range(n - 2, -1, -1):
            people.insert(i + people[i][1] + 1, people[i])
            people.remove(people[i])
        return people

s = Solution()
print(s.reconstructQueue([[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]))
