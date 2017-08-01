class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;

        map<int, int> myMap;
        for (int i = 0; i < n; i++) myMap[nums[i]]++;

        auto it1 = myMap.begin(), it2 = myMap.begin();
        int ret = 0;
        for (it2++; it2 != myMap.end(); it1++, it2++) {
            if (it2->first - it1->first == 1) ret = max(ret, it1->second + it2->second);
        }
        return ret;
    }
};
