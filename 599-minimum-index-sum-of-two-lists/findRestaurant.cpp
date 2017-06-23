class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ret;
        unordered_map<string, int> myMap;
        int sum = INT_MAX;
        for (int i = 0; i < list1.size(); i++) myMap[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++) {
            if (myMap.find(list2[i]) != myMap.end()) {
                if (myMap[list2[i]] + i < sum) {
                    ret.clear();
                    ret.push_back(list2[i]);
                    sum = myMap[list2[i]] + i;
                }
                else if (myMap[list2[i]] + i == sum) {
                    ret.push_back(list2[i]);
                }
            }
        }
        return ret;
    }
};
