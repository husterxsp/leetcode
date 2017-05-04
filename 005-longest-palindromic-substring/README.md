### 5. Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

Example:
```
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
```

Example:
```
Input: "cbbd"

Output: "bb"
```

Tag:
1. String

Similar Problems:
1. (H) Shortest Palindrome
2. (E) Palindrome Permutation
3. (H) Palindrome Pairs
4. (M) Longest Palindromic Subsequence

解题思路:
1. 遍历一遍字符串，每次遍历的字符作为中心点，向两边扩散来判断，注意奇数偶数的情况
2. 
