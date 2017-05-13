#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random

class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.eleList = []
        self.eleDict = {}

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.eleDict:
            return False
        self.eleList.append(val)
        self.eleDict[val] = len(self.eleList) - 1
        return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.eleDict:
            return False

        index = self.eleDict[val]
        last = self.eleList[-1]

        self.eleList[index] = last
        self.eleDict[last] = index

        del self.eleDict[val]
        self.eleList.pop()

        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        index = random.randint(0, len(self.eleList) - 1)
        return self.eleList[index]

obj = RandomizedSet()
obj.insert(3)
obj.remove(3)
obj.remove(0)
obj.insert(3)
obj.getRandom()
obj.remove(0)
