### 8. String to Integer (atoi)

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

Tag:
1. Math
2. String
Similar Problems
1. (E) Reverse Integer
2. (H) Valid Number

解题思路：
1. 注意处理异常（leetcode题解 https://discuss.leetcode.com/topic/2666/my-simple-solution）
    + discards all leading whitespaces
    + sign of the number
    + overflow
    + invalid input
2. 溢出的处理需要注意, [因为遇见过了atol，string to long 这样的问题，就不能用这种比当前数据类型长的方法解决] (http://www.cnblogs.com/springfor/p/3896499.html)

---
1. 有点不太懂，判断空格的那一步，while循环到最后，如果字符串都是空格不会出现溢出么？
