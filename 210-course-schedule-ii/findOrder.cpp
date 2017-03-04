#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> in(numCourses, 0);
    for (auto value : prerequisites) {
        graph[value.second].push_back(value.first);
        in[value.first]++;
    }
    queue<int> myQueue;
    vector<int> ret;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0) {
            myQueue.push(i);
            ret.push_back(i);
        }
    }
    while (!myQueue.empty()) {
        int q = myQueue.front();
        myQueue.pop();
        for (auto value : graph[q]) {
            in[value]--;
            if (in[value] == 0) {
                myQueue.push(value);
                ret.push_back(value);
            }
        }
    }
    for (auto i : in) {
        if (i != 0) ret.clear();
    }
    return ret;
}

int main () {
    vector<pair<int, int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    findOrder(4, prerequisites);
    return 0;
}
