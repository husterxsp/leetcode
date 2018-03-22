class Solution {
public:
    vector<vector<int>> dir{{-1, 0},{1, 0},{0, -1},{0, 1}};
    int startColor = -1;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // 注意一些边界条件的判断，比如不加这句就会导致死循环。
        if (image[sr][sc] == newColor) return image;

        if (startColor < 0) startColor = image[sr][sc];

        image[sr][sc] = newColor;
        for (int i = 0; i < 4; i++) {
            int x = sr + dir[i][0];
            int y = sc + dir[i][1];

            if (x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) continue;

            if (image[x][y] == startColor) floodFill(image, x, y, newColor);
        }
    }
    return image;
};
