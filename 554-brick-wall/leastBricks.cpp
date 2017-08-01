class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> myMap;
        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                myMap[sum]++;
            }
        }
        int maxV = 0;
        for (auto it : myMap) maxV = max(maxV, it.second);
        return wall.size() - maxV;
    }
};
