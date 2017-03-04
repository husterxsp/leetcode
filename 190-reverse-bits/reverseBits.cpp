#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0;
    for (int i = 0; i < 32; i++) {
        n & 1 ? ret |= 1 << (31 - i) : ret;
        n = n >> 1;
    }
    return ret;
}

int main () {
    uint32_t n = 1;
    cout << reverseBits(n) << endl;
    return 0;
}
