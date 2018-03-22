// easy
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0, secondLargest = 0, ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > largest) {
                secondLargest = largest;
                largest = nums[i];
                ret = i;
            }
            else if (nums[i] > secondLargest) {
                secondLargest = nums[i];
            }
        }
        if (largest >= 2 * secondLargest) return ret;

        return -1;
    }
};
