from collections import defaultdict

class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 0
        mid = 0
        myDict = defaultdict(lambda: 0)
        for c in s: myDict[c] += 1
        for key, value in myDict.items():
            ret += value;
            if value % 2 == 1:
                ret -= 1
                mid = True;
        return ret + 1 if mid else ret

s = Solution()
print(s.longestPalindrome("aaaav"))
