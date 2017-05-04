### 7. Reverse Integer

Reverse digits of an integer.

Example1: x = 123, return 321

Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Tag:
Math
Similar Problems:
1. (M) String to Integer (atoi)

解题思路：
1. 可以直接用转换为字符串再直接反转
2. 一个个取余数
3. 注意反转后可能溢出，以后这种涉及整数运算的都得考虑溢出！

leetcode 题解，厉害了，很简洁：
```
int reverse(int x) {
    long long res = 0;
    while(x) {
        res = res*10 + x%10;
        x /= 10;
    }
    return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}
```
