/*
    思路：简单的递归
**/

class Solution {
public:
    bool help(vector<string>& arr, int i, int j, vector<string>& allowed) {
        if (j > i) return true;

        for (int k = 0; k < allowed.size(); k++) {
            string tmp = allowed[k];
            if (tmp[0] == arr[i + 1][j] && tmp[1] == arr[i + 1][j + 1]) {
                arr[i][j] = tmp[2];
                if (j < i && help(arr, i, j + 1, allowed)) return true;
                if (j == i && help(arr, i - 1, 0, allowed)) return true;
            }
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int len = bottom.size();
        vector<string> arr(len, bottom);

        return help(arr, len - 2, 0, allowed);
    }
};