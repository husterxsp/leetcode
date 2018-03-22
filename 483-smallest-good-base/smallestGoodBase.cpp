参考：http://www.cnblogs.com/grandyang/p/6620351.html

b 表示 base, l 表示转换后的长度
则有以下关系：

n = 1 + b + b^2 + b^3 + b^4 + … + b^(l-1)
  = (b^l - 1) / (b - 1)

易知 b越大，l越小，b、l均大于等于2
b、l 范围：
2 <= b <= n-1
64 > l >= 2

如果直接遍历b的话，b的范围太大，会超时
所以考虑遍历l，l确定的话，问题就变为求解 方程 n = (b^l - 1) / (b - 1) 的b了。
没法直接解，不过函数单调，可以用二分来遍历。

另外可能有溢出的问题，所以需要缩小b、l的范围。
因为b最小2，所以l最大可以计算得 log2(n+1)
又   b^(l-1) < n ， 得 b < n^( 1/(l-1) )

2 <= b <= n^( 1/(l-1) )
log2(n + 1) >= l >= 2


string smallestGoodBase(string n) {
    long num = stol(n);
    for (int l = log(num + 1)/ log(2); l >= 2; l--) {
        // 注意pow里面写的 1.0，如果直接写1，那除完之后就为0了。
        // 可能会出现 pow(num, 1.0 / (l - 1)) = 2，而结果就是2的情况，如果直接写right = pow(num, 1.0 / (l - 1))
        // while 循环就不会执行了，所以需要加1.
        long left = 2, right = pow(num, 1.0 / (l - 1)) + 1;

        while (left < right) {
            long mid = left + (right - left) / 2, sum = 0;

            for (int j = 0; j < l; j++) {
                sum = sum * mid + 1;
            }
            // 使用pow会慢一些，而且pow各种坑，浮点数的省略小数位等等。
//            for (int i = 0; i < l; i++) {
//                sum += (long)pow((long double)mid, (long double)i);
//            }

            if (sum == num) return to_string(mid);
            if (sum > num) right = mid;
            else left = mid + 1;
        }
    }
    return to_string(num - 1);
}
