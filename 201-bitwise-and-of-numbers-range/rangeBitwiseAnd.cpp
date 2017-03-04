#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
int rangeBitwiseAnd(int m, int n) {
    int ret = m;
    for (int i = m + 1; i <= n; i++) {
        ret &= i;
    }
    return ret;
}
int main () {
    cout << rangeBitwiseAnd(5, 10) << endl;
    return 0;
}
