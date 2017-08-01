class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double average = sum / k;
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            average = max(average, sum / k);
        }
        return average;
    }
};
