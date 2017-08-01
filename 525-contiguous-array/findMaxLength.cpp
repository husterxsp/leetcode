class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), ret = 0, sum = 0;
        unordered_map<int, int> myMap;
        myMap[0] = 0;

        for (int i = 0; i < n; i++) {
            //  [0, 1] 映射到 [-1, 1] 便于计算
            sum += nums[i] * 2 - 1;
            if (myMap.find(sum) != myMap.end()) ret = max(ret, i + 1 - myMap[sum]);
            // 用i+1是因为还有个myMap[0]=0
            else myMap[sum] = i + 1;
        }
        return ret;
    }
};
