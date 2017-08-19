class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        multiset<int> mySet(nums.begin(), nums.begin() + k);

        int n = nums.size();

        for (int i = k; i <= n; i++) {
            int mid = (k + 1) / 2;
            double median;

            if (k % 2 == 1) median = *next(mySet.begin(), mid - 1);
            else median = ((double)*next(mySet.begin(), mid - 1) + (double)*(next(mySet.begin(), mid))) / 2;

            ret.push_back(median);

            mySet.insert(nums[i]);
            mySet.erase(mySet.find(nums[i - k]));
        }
        return ret;
    }
};
