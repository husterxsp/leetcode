#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>
/**
 wrong answer
 [[0,0],[1,0]]
 */
using namespace std;
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
int maxPoints(vector<Point>& points) {
    int ret = 0;
    for (int i = 0; i < points.size(); i++) {
        int nMax = 0, nSame = 0, nVertical = 0;
        unordered_map<float, int> comSlope;
        for (int j = i + 1; j < points.size(); j++) {
            if (points[i].x == points[j].x) {
                if (points[i].y == points[j].y) {
                    nSame++;
                }
                else {
                    nVertical++;
                }
                continue;
            }
            float slope = (float)(points[i].y - points[j].y) / (float)(points[i].x - points[j].x);
            comSlope[slope]++;
            nMax = max(nMax, comSlope[slope]);
        }
        nMax = max(nMax, nVertical) + 1 + nSame;
        ret = max(ret, nMax);
    }
    return ret;
}

int main() {
    vector<Point> points;
    points.push_back(Point(0, 0));
    points.push_back(Point(1, 0));
    cout << maxPoints(points) << endl;
    return 0;
}
