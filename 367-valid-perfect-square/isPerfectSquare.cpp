#include <iostream>

using namespace std;
bool isPerfectSquare(int num) {
    int left = 0, right = num, mid = 0;
    while (left <= right) {
        mid = right - (right - left) / 2;
        float tmp = (float)num / mid;
        if (tmp < mid) {
            right = mid - 1;
        }
        else if (tmp > mid) {
            left = mid + 1;
        }
        else {
            return true;
        }
    }
    return false;
}

int main() {
    cout << isPerfectSquare(16) << endl;
    return 0;
}
