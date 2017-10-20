class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> myMap;
        int maxFreq = 0;
        for (auto i : nums) {
            myMap[i]++;
            maxFreq = max(maxFreq, myMap[i]);
        }
        int left = 0, right = 0, ret = INT_MAX, n = nums.size(), curFreq = 0;

        unordered_map<int, int> curMap;
        while (left <= right && left < n) {
            while (right < n && curFreq < maxFreq) {
                curMap[nums[right]]++;
                curFreq = max(curFreq, curMap[nums[right]]);

                right++;
            }
            if (curFreq == maxFreq) ret = min(ret, right - left);

            curMap[nums[left]]--;
            left++;

            set<int> tmpSet;
            for (auto it : curMap) {
                tmpSet.insert(it.second);
            }

            curFreq = *tmpSet.rbegin();
        }
        return ret;
    }
};
