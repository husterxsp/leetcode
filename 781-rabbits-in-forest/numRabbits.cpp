class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for (int ans : answers) m[ans]++;

        int ret = 0;
        for (auto pair : m) {
            int first = pair.first;
            int second = pair.second;

            ret += (second / (first + 1)) * (first + 1);
            if (second % (first + 1) != 0) ret += first + 1;
        }

        return ret;
    }
};
