/**
    贪心，优先执行剩的比较多任务，任务之间互相插空

    大佬的解：
    https://discuss.leetcode.com/topic/92852/concise-java-solution-o-n-time-o-26-space
    http://www.cnblogs.com/grandyang/p/7098764.html
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    //    auto cmp = [](const int a, const int b) {
    //        return a > b;
    //    };

        map<char, int> myMap;
        for (char c : tasks) myMap[c]++;

        vector<int> v;
        for (auto it : myMap) v.push_back(it.second);
    //    sort(v.begin(), v.end(), cmp);

        sort(v.begin(), v.end(), greater<int>());

        int ret = 0;
        while (v.size()) {
            int task = 0;
            for (int i = 0; i < v.size(); i++) {
                v[i]--;

                if (v[i] == 0) {
                    v.erase(v.begin() + i);
                    i--;
                }
                task++;

                sort(v.begin(), v.end(), greater<int>());
                if (task == n + 1) break;
            }

            if (v.empty()) {
                ret += task;
            }
            else {
                ret += n + 1;
            }
        }
        return ret;
    }
};
