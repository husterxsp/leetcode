/**
    ???
    [[50,47],[95,48],[88,77],[84,3],[53,87],[98,79],[88,28],[13,22],[53,73],[85,55]]
*/
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <vector>
#include <unordered_map>

#include <time.h>

using namespace std;
vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    int n = positions.size(), curMax = 0;
    vector<int> ret(n);
    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        height[n] = positions[i].second;
    }
    for (int i = 0; i < n; i++) {
        pair<int, int> cur = positions[i];
        int maxHeight = 0;
        for (int j = 0; j < i; j++) {
             if ((cur.first + cur.second <= positions[j].first) || (cur.first >= positions[j].first + positions[j].second))
             continue;
            maxHeight = max(maxHeight, height[j]);
        }

        height[i] = maxHeight + cur.second;

        curMax = max(curMax, height[i]);

        ret[i] = curMax;
    }
    return ret;
}

int main() {
    vector<pair<int, int>> v{{50,47},{95,48},{88,77},{84,3},{53,87},{98,79},{88,28},{13,22},{53,73},{85,55}};
    fallingSquares(v);


    return 0;
}
