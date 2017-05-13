#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import random
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):

    def __init__(self, head):
        """
        @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
        :type head: ListNode
        """
        self.head = head;

    def getRandom(self):
        """
        Returns a random node's value.
        :rtype: int
        """
        i = 1;
        ret = self.head.val;

        p = self.head.next;
        while p != None:
            i += 1
            choice = random.randint(1, i)
            if choice == i:
                ret = p.val;
            p = p.next;
        return ret;

head = ListNode(1)
head.next = ListNode(2)
head.next.next = ListNode(3)
obj = Solution(head)
i = 1
while i < 1000:
    i += 1
    print(obj.getRandom())
