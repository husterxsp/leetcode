class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        map<char, int> myMap;
        for (char c : S) myMap[c]++;

        vector<pair<char, int>> arr;
        for (auto it : myMap) {
            arr.push_back({it.first, it.second});
        }

        sort(arr.begin(), arr.end(), [] (const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second;
        });

        int x = arr[0].second;
        if (n - x < x - 1) return "";

        string ret = "";

        ret.insert(0, x, arr[0].first);

        int k = 1;
        for (int i = 1; i < arr.size(); i++) {
            while (arr[i].second--) {
                ret.insert(k, 1, arr[i].first);
                k += 2;
                if (k > ret.size()) k = 1;
            }
        }
        return ret;
    }
};
