/**
    参考：https://discuss.leetcode.com/topic/93712/python-straightforward-with-explanation/6
*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        auto cmp = [](vector<int> const & a, vector<int> const & b) {
            return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
        };
        sort(courses.begin(), courses.end(), cmp);

        int sum = 0, n = courses.size();
        // vector<int> courseTake;
        // for (int i = 1; i < n; i++) {
        //     if () {
        //
        //     }
        // }

        priority_queue<int> pq;
        for (auto course : courses) {
            if (sum + course[0] <= course[1]) {
                pq.push(course[0]);
                sum += course[0];
            }
            else if (course[0] < pq.top) {
                sum += course[0] - pq.top;
                pq.pop();
                pq.push(course[0]);
            }
        }
        return pq.size();
    }
};
