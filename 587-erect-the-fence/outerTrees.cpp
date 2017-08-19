/**
    主要思路：凸包算法，Graham扫描
    但是此题对于在同一直线上的点也可能包括，主要难点是根据角度排序，对于角度相同的点按模长由小到大，
    但是还有特殊的情况需要处理。如[[2,1],[1,4],[1,3],[1,2],[0,3]]。
    参考：
    http://www.cnblogs.com/quintessence/p/6852902.html
    http://www.cnblogs.com/devymex/archive/2010/08/09/1795392.html
*/
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
bool operator==(const Point &a, const Point &b) {
    return (a.x == b.x && a.y == b.y);
}
class Solution {
public:
    // 判断是否是逆时针
    static int ccw(Point a, Point b, Point c) {
        int direction = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (direction > 0) return 1;
        else if (direction < 0) return -1;
        return 0;
    }
    static int distance(Point a, Point b) {
        return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    }
    // vector 比较函数传入一个参数
    // https://stackoverflow.com/questions/4066576/passing-a-parameter-to-a-comparison-function
    struct comparePolar {
        Point p;
        comparePolar(Point p): p(p){}
        bool operator () (const Point &a, const Point &b) {
            int direction = ccw(p, a, b);
            if (direction == 0) return distance(p, a) < distance(p, b);
            return direction == 1;
        }
    };
    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size();
        if (n <= 3) return points;

        //找到最低点
        Point base = points[0];
        int baseIndex = 0;
        for (int i = 0; i < n; i++) {
            Point it = points[i];
            if (it.y < base.y || (it.y == base.y && it.x < base.x)) {
                base = it;
                baseIndex = i;
            }
        }
        points.erase(points.begin() + baseIndex);
        sort(points.begin(), points.end(), comparePolar(base));

        // 关键点
        Point pn = points.back();
        if (ccw(base, points[0], pn) != 0) {//非所有点都共线
            int idx = points.size() - 1;
            while (ccw(base, points[idx], pn) == 0) idx--;
            reverse(points.begin() + idx + 1, points.end());
        }

        vector<Point> hull{base, points[0]};
        for (int i = 1; i < points.size(); i++) {
            while (ccw(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) == -1) {
                // 删除顺时针的点 top
                hull.pop_back();
            }
            hull.push_back(points[i]);
        }

        return hull;
    }
};
