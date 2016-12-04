#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 思路：位运算。。。
int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        int mask = 1 << i;
        int sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] & mask) {
                sum++;
            }
        }
        ret = (ret << 1) + (sum % 3);
    }
    return ret;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 2, 1111111};
    cout << singleNumber(arr) << endl;
    return 0;
}
