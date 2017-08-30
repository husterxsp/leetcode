#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
/**
    解法1，用map
*/
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> ret;
    unordered_map<int, int> myMap;
    int n = nums.size();
    for (int i = 0; i < n; i++) myMap[nums[i]] = i;
    for (auto num : findNums) {
        int j = myMap[num] + 1;
        for (; j < n; j++) {
            if (nums[j] > num) {
                ret.push_back(nums[j]);
                break;
            }
        }
        if (j == n) ret.push_back(-1);
    }
    return ret;
}
/**
    解法2，栈
    例如 [4,3,2,1]这样的逆序数组，上面的用map的时间复杂度O(n^2), 用一下的栈则是O(n)
*/
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    vector<int> ret;
    stack<int> myStack;
    unordered_map<int, int> myMap;
    for (int num : nums) {
        while (!myStack.empty() && num > myStack.top()) {
            myMap[myStack.top()] = num;
            myStack.pop();
        }
        myStack.push(num);
    }
    for (int num : findNums) {
        ret.push_back(myMap.find(num) == myMap.end() ? -1 : myMap[num]);
    }
    return ret;
}
int main(){
    vector<int> findNums{4,1,2};
    vector<int> nums{1,3,4,2};
    nextGreaterElement(findNums, nums);
    return 0;
}
