#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
/**
    暴力解法果然超时。。TLE...
*/
int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int n = points.size();
    vector<vector<int>> distinct(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = points[i].first - points[j].first;
            int y = points[i].second - points[j].second;
            distinct[i][j] = x * x + y * y;
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                if (distinct[i][j] == distinct[i][k]) ret++;
            }
        }
    }
    return ret;
}
/**
    AC
    用map, 另外就是不必把所有的距离都保存下来再计算，这样会超出内存限制。
    如下第一个for循环内就计算ret, 并clear map
    或者直接将distinct 放在for 循环里面。。。
*/
int numberOfBoomerangs(vector<pair<int, int>>& points) {
    int n = points.size(), ret = 0;
    unordered_map<int, int> distinct;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = points[i].first - points[j].first;
            int y = points[i].second - points[j].second;
            distinct[x * x + y * y]++;
        }
        for (auto it : distinct) {
            // 组合数公式 c(m,n)=p(m,n)/n!=m!/((m-n)!*n!)， 此处是C(n, 2)
            if (it.second > 1) ret += it.second * (it.second - 1);
        }
        distinct.clear();
    }
    return ret;
}

int main() {
    vector<pair<int, int>> points = {{0,0},{1,0},{2,0}};
    cout << numberOfBoomerangs(points) << endl;
    return 0;
}
