// 直接就暴力解了。。不知道有啥玄机。。contest的时候被hard吓住了
class Solution {
public:
    void swap(int i, int j, vector<int>& row, map<int, int>& m) {
        m[row[i]] = j;
        m[row[j]] = i;

        int tmp = row[i];
        row[i] = row[j];
        row[j] = tmp;
    }
    int minSwapsCouples(vector<int>& row) {
        map<int, int> m;
        for (int i = 0; i < row.size(); i++) {
            m[row[i]] = i;
        }

        int ret = 0;
        for (int i = 0; i < row.size(); i += 2) {
            if (row[i] % 2 == 0) {
                if (row[i + 1] != row[i] + 1) {
                    swap(i + 1, m[row[i] + 1], row, m);
                    ret++;
                }
            }
            else {
                if (row[i + 1] != row[i] - 1) {
                    swap(i + 1, m[row[i] - 1], row, m);
                    ret++;
                }
            }
        }
        return ret;
    }
};
