#include <iostream>
#include <vector>
#include <Map>
#include <Set>

using namespace std;
/**
 参考：
 http://www.cnblogs.com/grandyang/p/4534586.html

 http://www.cnblogs.com/easonliu/p/4531020.html

 说好的二叉索引树解呢。。。
 */
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> height, ret;
    multiset<int> mySet;

    int pre = 0, cur = 0;
    for (auto v : buildings) {
        height.push_back({v[0], -v[2]});
        height.push_back({v[1], v[2]});
    }
    sort(height.begin(), height.end());
    mySet.insert(0);
    for (auto v : height) {
        if (v.second < 0) mySet.insert(-v.second);
        else mySet.erase(mySet.find(v.second));

        cur = *mySet.rbegin();

        if (cur != pre) {
            ret.push_back({v.first, cur});
            pre = cur;
        }
    }
    return ret;
}

int main () {
    vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    getSkyline(buildings);
    return 0;
}
