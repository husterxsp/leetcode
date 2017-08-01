class Solution {
public:
    /**
        虽然能A,但是效率有点低。。。beat 1.13%
    */
    int search(map<int, int> myMap, int len, int curLen, int borders) {
        if (curLen == len) {
            borders++;
            if (borders == 4) return true;
            return search(myMap, len, 0, borders);
        }
        for (auto it = myMap.begin(); it != myMap.end(); it++) {
            if (it->second == 0) continue;
            if (curLen + it->first > len) break;

            it->second--;
            if (search(myMap, len, curLen + it->first, borders)) return true;
            it->second++;
        }
        return false;
    }
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0 || nums.size() < 4) return false;

        map<int, int> myMap;
        for (auto num : nums) myMap[num]++;

        return search(myMap, sum / 4, 0, 0);
    }
};
