#include <iostream>
#include <vector>

using namespace std;
int thirdMax(vector<int>& nums) {
    vector<int> ret;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < ret.size()) {
            if (nums[i] >= ret[j]) break;
            j++;
        }
        if (j < ret.size() && nums[i] == ret[j]) continue;
        ret.insert(ret.begin() + j, nums[i]);
    }
    return ret.size() >= 3 ? ret[2] : ret[0];
}

int main() {
    vector<int> nums = {1,2,2,5,3,5};
    cout << thirdMax(nums) << endl;
    return 0;
}
