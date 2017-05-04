### 2. Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

Tag:
1. Linked List
2. Math

Similar Problems
1. (M) Multiply Strings
2. (E) Add Binary
3. (E) Sum of Two Integers
4. (E) Add Strings
5. (M) Add Two Numbers II

两个数字的加法运算
解法思路:
1. 直接合并，注意链表题目一般设置一个dummy节点会方便很多

---
第二次做又做错了。。
1. while运算条件应该是 (l1 || l2). 不应该是写成(l1 && l2),
2. 注意不要忽略循环结束后的剩余的进位。
