/**
    注意各种边界条件
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.empty()) return 0;

        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) myMap[nums[i]]++;

        int ret = 0;
        if (k == 0) {
            for (auto it : myMap) {
                if (it.second > 1) ret++;
            }
        }
        else {
            auto p1 = myMap.begin(), p2 = myMap.begin();
            p2++;
            while (p1 != myMap.end()) {
                while (p2 != myMap.end()) {
                    if (p2->first - p1->first == k) ret++;
                    else if (p2->first - p1->first > k) break;
                    p2++;
                }
                p1++;
            }
        }
        return ret;
    }
};

// 改进。。应该用unordered_map的。。。
// 但是好像效率还没上面的map高，myMap.find查找也需要时间
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0 || nums.empty()) return 0;

        map<int, int> myMap;
        for (int i = 0; i < nums.size(); i++) myMap[nums[i]]++;

        int ret = 0;
        for (auto it : myMap) {
            if (k == 0 && it.second > 1) ret++;
            else if (k > 0 && myMap.find(it.first + k) != myMap.end()) ret++;
        }
        return ret;
    }
};
