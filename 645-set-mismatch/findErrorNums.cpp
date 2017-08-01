class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum = 0, n = nums.size();
        unordered_map<int, int> myMap;
        for (auto num : nums) {
            myMap[num]++;
            sum += num;
        }

        auto it = myMap.begin();
        while (it != myMap.end()) {
            if (it->second == 2) break;
            it++;
        }

        vector<int> ret(2);
        ret[0] = it->first;
        ret[1] = n * (n + 1) / 2 + it->first - sum;

        return ret;
    }
};
