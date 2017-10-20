class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [](std::pair<string, int> const & a, std::pair<string, int> const & b) {
            return a.second != b.second?  a.second > b.second : a.first < b.first;
        };
        map<string, int> myMap;
        for (string s : words) myMap[s]++;

        vector<pair<string, int>> myVec;
        for (auto it : myMap) myVec.push_back({it.first, it.second});
        sort(myVec.begin(), myVec.end(), cmp);

        vector<string> ret;
        for (int i = 0; i < k; i++) {
            ret.push_back(myVec[i].first);
        }
        return ret;
    }
};

/*
    改进？。。beat 0.96%...效率更低了
*/
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        auto cmp = [](pair<string, int> const & a, pair<string, int> const & b) {
            return a.second != b.second? a.second > b.second : a.first < b.first;
        };
        map<string, int> myMap;
        for (string s : words) myMap[s]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> pq(cmp);
        for (auto itor : myMap) {
            pq.push({itor.first,itor.second});
            if (pq.size() > k) pq.pop();
        }

        vector<string> ret;
        while (!pq.empty()) {
            ret.insert(ret.begin(), pq.top().first);
            pq.pop();
        }
        return ret;
    }
};
