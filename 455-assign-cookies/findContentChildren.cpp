#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;
/**
    TLE...
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort (g.begin(), g.end());
    multiset<int> mySet(s.begin(), s.end());

    int n = g.size(), ret = 0;
    for (int i = 0; i < n; i++) {
        auto itor = lower_bound(mySet.begin(), mySet.end(), g[i]);
        if (itor != mySet.end()) {
            ret++;
            mySet.erase(mySet.begin(), itor);
        }
        else break;
    }
    return ret;
}
/**
    AC
*/
int findContentChildren(vector<int>& g, vector<int>& s) {
    sort (g.begin(), g.end());
    sort (s.begin(), s.end());

    int gSize = g.size(), sSize = s.size(), i = 0, j = 0, ret = 0;
    for (i = 0; i < gSize; i++) {
        while (j < sSize && g[i] > s[j]) j++;
        if (j < sSize) {
            ret++;
            j++;
        }
        else break;
    }
    return ret;
}

int main() {

    vector<int> g{1,2,3,4, 5};
    vector<int> s{1,1,1,1,1,1,1,1,1,5,5,5,5,5};
    cout << findContentChildren(g, s) << endl;
    return 0;
}
