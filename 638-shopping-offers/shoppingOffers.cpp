class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int ret = 0;
        for (int i = 0; i < needs.size(); i++) ret += price[i] * needs[i];

        for (int i = 0; i < special.size(); i++) {
            int j = 0;
            for (j = 0; j < needs.size(); j++) if (needs[j] < special[i][j]) break;
            if (j < needs.size()) continue;

            for (j = 0; j < needs.size(); j++) needs[j] -= special[i][j];
            ret = min(ret, special[i].back() + shoppingOffers(price, special, needs));
            for (j = 0; j < needs.size(); j++) needs[j] += special[i][j];
        }
        return ret;
    }
};
