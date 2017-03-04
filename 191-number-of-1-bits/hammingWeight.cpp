#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
int hammingWeight(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        n & 1 ? ret++ : ret;
        n >>= 1;
    }
    return ret;
}

int main () {
    uint32_t n = 11;
    cout << hammingWeight(n) << endl;
    return 0;
}
