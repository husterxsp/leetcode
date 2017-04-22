#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
bool isPowerOfFour(int num) {
    int bit = 0, tmp = num;
    while (tmp > 0) {
        tmp >>= 1;
        bit++;
    }
    return bit % 2 == 1 && num == (1<<(bit-1));
}

// bool isPowerOfFour(int num) {
//     return num > 0 && !(num & (num - 1)) && (num & 0x55555555) == num;
// }

int main() {
    cout << isPowerOfFour(128) << endl;
    return 0;
}
