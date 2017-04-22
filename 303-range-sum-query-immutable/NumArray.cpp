#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> nums) {
        sum = nums;
        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i - 1];
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) return sum[j];
        return sum[j] - sum[i - 1];
    }
};

int main () {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray obj = *new NumArray(nums);
    cout << obj.sumRange(0, 5) << endl;
    return 0;
}
