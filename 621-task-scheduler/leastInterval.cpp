class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> myMap;
        for (char c : tasks) myMap[c]++;

        int ret = 0, idle = 0;
        while (myMap.size()) {
            ret += myMap.size();
            if (n >= myMap.size()) idle = n - myMap.size() + 1;
            for (auto it = myMap.cbegin(); it != myMap.cend();) {
                char c = it->first;
                myMap[c]--;
                if (myMap[c] == 0) {
                    myMap.erase(it++);
                }
                else
                {
                    ++it;
                }
            }
            if (myMap.size()) {
                ret += idle;
                idle = 0;
            }
        }
        return ret;
    }
};
