/**
    BFS 超时
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
bool canTransform(string start, string end) {
    map<char, int> m1, m2;
    for (char c : start) m1[c]++;
    for (char c : end) m2[c]++;

    for (auto pair : m1) {
        if (pair.second != m2[pair.first]) return false;
    }

    set<string> vis;

    queue<string> q;
    q.push(start);

    vis.insert(start);
    while (!q.empty()) {

        string cur = q.front();
        q.pop();

        if (cur == end) return true;

        for (int i = 0; i < cur.size() - 1; i++) {
            string tmp = cur;
            if (tmp[i] == 'X' && tmp[i + 1] == 'L' || tmp[i] == 'R' && tmp[i + 1] == 'X') {
                swap(tmp[i], tmp[i + 1]);

                if (vis.find(tmp) != vis.end()) continue;
                q.push(tmp);
            }
        }
    }
    return false;
}

int main() {
    cout << canTransform("XRXXLXLXXXXRXXXXLXXL", "XXRXLXXLXXRLXXXLXXXX") << endl;
    return 0;
}


/**
    找规律，智力题。参考：https://discuss.leetcode.com/topic/119518/c-o-n-solution
    题目中只包含 X、R、L 三种字符
    其中 L可以向前移动，R可以向后移动。所以end中的L应该在start的前面，end中的R应该在start的后面。
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) return false;

        // remove 'X's
        vector<pair<int,int>> s, e;
        for (int i = 0; i < (int)start.length(); i++) {
            if (start[i] != 'X') s.emplace_back(start[i], i);
            if (end[i] != 'X') e.emplace_back(end[i], i);
        }

        // compare the sizes of 'L's and 'R's
        if (s.size() != e.size()) return false;

        // compare the positions of 'L's and 'R's
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i].first != e[i].first ||
                s[i].first == 'L' && s[i].second < e[i].second ||
                s[i].first == 'R' && s[i].second > e[i].second ) return false;
        }

        return true;
    }
};
