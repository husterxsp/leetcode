#include <iostream>
using namespace std;
// wrong awswer:
//Input: 7
//Output: 3
//Expected: 2
// TLE超时, 原因是乘法溢出
//input: 2147395599

// 卧槽乘法溢出，就用除法啊！
// 关于此题需要注意的一些边界条件，
//1. while循环的条件，要不要 =
//2. left的起始条件是0还是1
//3. 乘法溢出
//4. 本题AC的条件开方应该是向下取整
int mySqrt(int x) {
    if (x <= 1) {
        return x;
    }
    int left = 0, right = x, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (x / mid == mid) {
            return mid;
        }
        if (x / mid < mid) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

int main()
{
    cout << mySqrt(9) << endl;
    return 0;
}
