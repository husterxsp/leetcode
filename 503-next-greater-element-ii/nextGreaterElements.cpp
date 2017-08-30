/*
    思路：利用栈，整体循环两边
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n, -1);

        stack<pair<int, int>> myStack;

        unordered_map<int, int> myMap;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < n; i++) {
                while (!myStack.empty() && nums[i] > myStack.top().second) {
                    ret[myStack.top().first] = nums[i];
                    myStack.pop();
                }
                myStack.push({i, nums[i]});
            }
        }
        return ret;
    }
};
