#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
 一开始都看不懂题目。。。。
 */
int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    if (n == 1) return 10;
    int ret = 10;
    int product = 9;
    for (int i = 1; i < n && i < 10; i++) {
        product *= 10 - i;
        ret += product;
    }
    return ret;
}

int main() {
    cout << countNumbersWithUniqueDigits(2) << endl;
    return 0;
}
