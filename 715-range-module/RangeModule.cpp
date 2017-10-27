/**
    这题。。太简单。。
*/
class RangeModule {
public:

    RangeModule() {

    }

    void addRange(int left, int right) {
        // 先插入
        for (int i = 0; i < v.size(); i++) {
            if (left > v[i][1] || right < v[i][0]) continue;
            v[i][0] = min(v[i][0], left);
            v[i][1] = max(v[i][1], right);
        }
        v.push_back({left, right});
        sort(v.begin(), v.end());
        // 再合并
        for (int i = 1; i < v.size(); i++) {
            if (v[i][0] <= v[i - 1][1]) {
                v[i - 1][1] = max(v[i - 1][1], v[i][1]);
                v.erase(v.begin() + i);
                i--;
            }
        }
    }

    bool queryRange(int left, int right) {
        for (int i = 0; i < v.size(); i++) {
            if (left >= v[i][0] && right <= v[i][1]) {
                return true;
            }
        }
        return false;
    }

    void removeRange(int left, int right) {
        for (int i = 0; i < v.size(); i++) {
            if (right <= v[i][0]) break;
            if (left >= v[i][1]) continue;

            if (left <= v[i][0]) {
                v[i][0] = right;
            }
            else if (right >= v[i][1]) {
                v[i][1] = left;
            }
            else {
                int tmp = v[i][1];
                v[i][1] = left;

                v.insert(v.begin() + i + 1, {right, tmp});

            }
        }
    }
private:
    vector<vector<int>> v;
};
