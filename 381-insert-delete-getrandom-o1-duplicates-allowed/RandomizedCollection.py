#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# 然而python没有mulitmap...π_π

import collections
import random
class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.eleList = []
        self.eleDict = collections.defaultdict(set)

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        ret =  val not in self.eleDict
        self.eleList.append(val)
        self.eleDict[val].add(len(self.eleList) - 1)
        return ret

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        if val not in self.eleDict:
            return False

        last = self.eleList.pop()
        self.eleDict[last].remove(len(self.eleList))

        if val != last:
            index = self.eleDict[val].pop()
            self.eleDict[last].add(index)
            self.eleList[index] = last
        if not self.eleDict[val]:
            del self.eleDict[val]
        return True

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        index = random.randint(0, len(self.eleList) - 1)
        return self.eleList[index]


obj = RandomizedCollection()
obj.insert(3)
obj.remove(3)
# obj.remove(0)
# obj.insert(3)
# obj.getRandom()
# obj.remove(0)
