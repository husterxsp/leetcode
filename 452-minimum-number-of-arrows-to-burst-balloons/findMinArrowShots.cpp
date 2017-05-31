class Solution {
public:
    static bool compare(pair<int, int>&i, pair<int, int>&j) {
        if (i.first < j.first) return true;
        else if (i.first == j.first) return i.second < j.second;
        return false;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int last = 0, n = points.size(), ret = 0;
        if (!n) return 0;

        sort(points.begin(), points.end(), compare);

        int min_end = points[0].second;
        for (int i = 1; i < n; i++) {
            if (points[i].first > min_end) {
                ret++;
                min_end = points[i].second;
            }
            else {
                min_end = min(min_end, points[i].second);
            }
        }
        return ret + 1;
    }
};
