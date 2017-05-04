### 6. ZigZag Conversion

The string `PAYPALISHIRING` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```
And then read line by line: `PAHNAPLSIIGYIR`
Write the code that will take a string and make this conversion given a number of rows:
```
string convert(string text, int nRows);
```
`convert("PAYPALISHIRING", 3)` should return `PAHNAPLSIIGYIR`.


解题思路：
1. 字符串处理，找数学规律。。注意斜着排的字符与竖着排的字符的长度关系
2. 区分首尾行和其他行 http://www.cnblogs.com/springfor/p/3889414.html
3. 注意 numRows == 1的初始情况
---
二刷。。依旧找不到规律。。心塞
