/*
    思路：先排序，再一个个遍历
*/
class Solution {
public:
    struct sortByPC {
        bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first > b.first) return true;
            else if (a.first == b.first) return a.second < b.second;
            return false;
        }
    };
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        multiset<pair<int, int>, sortByPC> s;

        for (int i = 0; i < Profits.size(); i++) s.insert(pair<int, int>(Profits[i], Capital[i]));

        for (auto it = s.begin(); it != s.end() && k; ) {
            if (it->second <= W) {
                W += it->first;
                k--;

                s.erase(it);
                it = s.begin();
            }
            else it++;
        }
        return W;
    }
};
