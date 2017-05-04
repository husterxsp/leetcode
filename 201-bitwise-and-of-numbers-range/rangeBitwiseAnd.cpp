#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

/**
    找规律题？
    有个疑问，为啥只用比较第一个和最后一个？
    因为最大的数和最小的数相同的部分，中间也相同
*/
using namespace std;
int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    while (m != n) {
        m >>= 1;
        n >>= 1;
        i++;
    }
    return m<<i;
}
int main () {
    cout << rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
