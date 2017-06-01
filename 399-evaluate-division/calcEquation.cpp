#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
    思路：构造一个图，另外用一个vis保存已访问过的节点，避免死循环
*/
double searchGraph(unordered_map<string, unordered_map<string, double>> &myGraph,
                   string first, string second, unordered_set<string> vis) {

    if (myGraph.find(first) == myGraph.end() || myGraph.find(second) == myGraph.end()) return -1.0;
    if (first == second) return 1.0;
    if (myGraph[first].find(second) != myGraph[first].end()) return myGraph[first][second];

    double ret = -1;
    for (auto itor : myGraph[first]) {
        if (vis.find(itor.first) != vis.end()) continue;
        vis.insert(first);
        double tmp = searchGraph(myGraph, itor.first, second, vis);
        vis.erase(first);
        if (tmp != -1) {
            ret = tmp * myGraph[first][itor.first];
            myGraph[first][second] = ret;
            break;
        }
    }
    return ret;
}
vector<double> calcEquation(vector<pair<string, string>> equations,
                            vector<double>& values, vector<pair<string, string>> queries) {

    unordered_map<string, unordered_map<string, double>> myGraph;
    int n = equations.size();
    for (int i = 0; i < n; i++) {
        string first = equations[i].first, second = equations[i].second;
        myGraph[first][second] = values[i];
        myGraph[second][first] = 1 / values[i];
    }

    vector<double> ret;
    unordered_set<string> vis;
    for (auto query : queries) {
        ret.push_back(searchGraph(myGraph, query.first, query.second, vis));
    }
    return ret;
}

int main() {
    vector<pair<string, string>> equations{{"a","b"},{"b","c"},{"a","d"}};
    vector<double> values{2.0,3.0, 1.0};
    vector<pair<string, string>> queries{ {"a","c"},{"b","c"},{"a","e"},{"a","a"},{"x","x"},{"d","c"},{"d", "b"}};

    calcEquation(equations, values, queries);
    return 0;
}
