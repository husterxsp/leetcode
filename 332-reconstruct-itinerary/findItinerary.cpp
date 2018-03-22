/**
    几点需要注意：
    1. map利用的是multiset而不是set，可能有重复的线路
    2. set先删除再插入，地址变了？怎么访问总是出错
*/
有向图的欧拉通路
class Solution {
public:
    void search(unordered_map<string, multiset<string>>& myMap, string key, vector<string>& ret) {
        while (myMap[key].size()) {
            string capital = *myMap[key].begin();
            myMap[key].erase(myMap[key].begin());
            search(myMap, capital, ret);
        }
        ret.push_back(key);
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string, multiset<string>> myMap;
        for (auto t : tickets) {
            myMap[t.first].insert(t.second);
        }
        vector<string> ret;
        search(myMap, "JFK", ret);
        return vector<string>(ret.rbegin(), ret.rend());;
    }
};
