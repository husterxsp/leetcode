/**
    一开始的想的两种办法都无法AC。。。
    解法1：二维数组，TLE
*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> maxRect = rectangles[0];
        int n = rectangles.size();
        for (int i = 1; i < n; i++) {
            maxRect[0] = min(maxRect[0], rectangles[i][0]);
            maxRect[1] = min(maxRect[1], rectangles[i][1]);
            maxRect[2] = max(maxRect[2], rectangles[i][2]);
            maxRect[3] = max(maxRect[3], rectangles[i][3]);
        }

        vector<vector<int>> maxRectangles((maxRect[2] - maxRect[0]), vector<int>(maxRect[3] - maxRect[1]));

        int xOffset = -maxRect[0], yOffset = -maxRect[1];

        for (int i = 0; i < n; i++) {
            for (int j = rectangles[i][0]; j < rectangles[i][2]; j++) {
                for (int k = rectangles[i][1]; k < rectangles[i][3]; k++) {
                    maxRectangles[j + xOffset][k + yOffset]++;
                    if (maxRectangles[j + xOffset][k + yOffset] > 1) return false;
                }
            }
        }

        for (int i = 0; i < maxRectangles.size(); i++) {
            for (int j = 0; j < maxRectangles[0].size(); j++) {
                if (maxRectangles[i][j] == 0) return false;
            }
        }
        return true;
    }
};

/**
    解法二：wrong answer：[[0,0,1,1],[0,0,1,1],[1,1,2,2],[1,1,2,2]]
*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<int> maxRect = rectangles[0];
        int n = rectangles.size();
        for (int i = 0; i < n; i++) {
            maxRect[0] = min(maxRect[0], rectangles[i][0]);
            maxRect[1] = min(maxRect[1], rectangles[i][1]);
            maxRect[2] = max(maxRect[2], rectangles[i][2]);
            maxRect[3] = max(maxRect[3], rectangles[i][3]);
        }

        vector<int> row(maxRect[2] - maxRect[0]), col(maxRect[3] - maxRect[1]);
        int xOffset = -maxRect[0], yOffset = -maxRect[1];

        for (int i = 0; i < n; i++) {
            // row
            int len = rectangles[i][3] - rectangles[i][1];
            for (int j = rectangles[i][0]; j < rectangles[i][2]; j++) row[j + xOffset] += len;
            // col
            len = rectangles[i][2] - rectangles[i][0];
            for (int j = rectangles[i][1]; j < rectangles[i][3]; j++) col[j + yOffset] += len;
        }

        for (int i = 0; i < row.size(); i++) {
            if (row[i] != maxRect[3] - maxRect[1]) return false;
        }

        for (int i = 0; i < col.size(); i++) {
            if (col[i] != maxRect[2] - maxRect[0]) return false;
        }
        return true;
    }
};
