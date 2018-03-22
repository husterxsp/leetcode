拓扑排序

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
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> in(numCourses, 0);
    for (auto value : prerequisites) {
        graph[value.second].push_back(value.first);
        in[value.first]++;
    }
    queue<int> myQueue;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == 0) myQueue.push(i);
    }
    while (!myQueue.empty()) {
        int q = myQueue.front();
        myQueue.pop();
        for (auto value : graph[q]) {
            in[value]--;
            if (in[value] == 0) myQueue.push(value);
        }
    }
    for (auto i : in) {
        if (i != 0) return false;
    }
    return true;
}

int main () {
    vector<pair<int, int>> prerequisites = {{0,1},{1,0}};
    cout << canFinish(2, prerequisites) << endl;
    return 0;
}
