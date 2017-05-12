#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
/**
 考数学？这怎么玩。。。
 四平方和定理: 每个正整数均可表示为4个整数的平方和
 */


/**
 递归解
 */
 int numSquares(int n) {
     while (n && n % 4 == 0) n /= 4;
     if (n % 8 == 7) return 4;

     int ret = n, num = 1;
     while (num * num <= n) {
         int a = n / (num * num), b = n % (num * num);
         ret = min(ret, a + numSquares(b));
         num++;
     }
     return ret;
 }

int main () {
    cout << numSquares(1) << endl;
    return 0;
}
