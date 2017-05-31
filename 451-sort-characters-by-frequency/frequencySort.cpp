#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

static bool compare(pair<char, int>&i, pair<char, int>&j) {
    return i.second >= j.second;
}
string frequencySort(string s) {
    map<char, int> myMap;
    for (char c : s) myMap[c]++;

    vector<pair<char, int>> tmpVec(myMap.begin(), myMap.end());
    sort(tmpVec.begin(), tmpVec.end(), compare);

    string ret = "";
    for (auto itor : tmpVec) {
        while (itor.second-- > 0) ret += itor.first;
    }
    return ret;
}

int main() {
    cout << frequencySort("aaccc") << endl;
    return 0;
}
