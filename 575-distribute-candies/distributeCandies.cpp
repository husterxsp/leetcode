class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> mySet(candies.begin(), candies.end());
        int kind = mySet.size(), n = candies.size();

        if (kind > n / 2) return n / 2;
        return kind;
    }
};
