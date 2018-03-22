/*
    Easy...
*/
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        while (V-- > 0) {
            // move left
            int move = K;
            for (int i = K; i > 0; i--) {
                if (heights[i - 1] < heights[i]) {
                    move = i - 1;
                }
                else if (heights[i - 1] > heights[i]) {
                    break;
                }

            }
            if (move != K) {
                heights[move]++;
                continue;
            }

            for (int i = K; i < heights.size() - 1; i++) {
                if (heights[i] > heights[i + 1]) {
                    move = i + 1;
                }
                else if (heights[i] < heights[i + 1]) break;
            }
            heights[move]++;
        }
        return heights;
    }
};