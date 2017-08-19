/**
    参考网上解：http://www.cnblogs.com/grandyang/p/7200016.html
*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ret;
        vector<vector<int>> vec;
        unordered_map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) {
            for (int num : nums[i]) {
                vec.push_back({num, i});
            }
        }

        sort(vec.begin(), vec.end());
        int left = 0, k = nums.size(), cnt = 0, diff = INT_MAX;

        for (int right = 0; right < vec.size(); right++) {
            if (myMap[vec[right][1]]++ == 0) cnt++;

            while (cnt == k && left <= right) {
                if (diff > vec[right][0] - vec[left][0]) {
                    diff = vec[right][0] - vec[left][0];
                    ret = {vec[left][0], vec[right][0]};
                }
                if (--myMap[vec[left][1]] == 0) cnt--;
                left++;
            }
        }
        return ret;
    }
};
