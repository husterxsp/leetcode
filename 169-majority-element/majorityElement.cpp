#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int retTime = 1, retEle = nums[0], tmpTime = 1, tmpEle = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i - 1] == nums[i]) {
            tmpTime++;
            tmpEle = nums[i - 1];
        }
        else {
            if (retTime < tmpTime) {
                retTime = tmpTime;
                retEle = tmpEle;
            }
            tmpTime = 1;
            tmpEle = nums[i];
        }
    }
    if (retTime < tmpTime) {
        retTime = tmpTime;
        retEle = tmpEle;
    }
    return retEle;
}

int main () {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    majorityElement(nums);
    return 0;
}
