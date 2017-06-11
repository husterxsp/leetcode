class Solution {
public:
    // 虽然是easy...但是还是看了答案解释...
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int ret = 0, startIndex = 0;
        for (int i = 0; i < houses.size(); i++) {
            int tmpMin = INT_MAX;
            for (int j = startIndex; j < heaters.size(); j++) {
                if (abs(houses[i] - heaters[j]) <= tmpMin) {
                    tmpMin = abs(houses[i] - heaters[j]);
                }
                else {
                    startIndex = j - 1;
                    break;
                }
            }
            ret = max(ret, tmpMin);
        }
        return ret;
    }
};
