class Solution {
public:
    /**
        思路比较清楚，但是一些特殊情况注意考虑，比如移除一部分后导致新的连接在一块儿，注意提高编码速度
    */
    void remove(string &board, int pos) {
        int left = pos, right = pos;
        while (left >= 0 && board[left] == board[pos]) left--;
        while (right < board.size() && board[right] == board[pos]) right++;
        left++;
        if (right - left >= 3) {
            board.erase(left, right - left);
            remove(board, left);
        }
    }
    int findMinStep(string board, string hand) {
        if (board.size() == 0) return 0;
        else if (hand.size() == 0) return -1;

        int m = board.size(), n = hand.size(), ret = INT_MAX;
        // 遍历hand,因为不清楚insert的顺序
        for (int i = 0; i < n; i++) {
            // 在board中找到hand[i]的位置和长度
            vector<vector<int>> pos_len;
            int len = 0, j = 0;
            for (; j < m; j++) {
                if (board[j] == hand[i]) len++;
                else if (len > 0) {
                    pos_len.push_back({j - len, len});
                    len = 0;
                }
            }
            if (len > 0) pos_len.push_back({j - len, len});

            for (int k = 0; k < pos_len.size(); k++) {
                string tmpBoard = board;
                string tmpHand = hand;

                tmpHand.erase(i, 1);
                if (pos_len[k][1] >= 2) {
                    tmpBoard.erase(pos_len[k][0], pos_len[k][1]);

                    // 注意删除掉一部分后，可能导致新的连在一块儿了
                    remove(tmpBoard, pos_len[k][0]);

                    int tmp = findMinStep(tmpBoard, tmpHand);
                    if (tmp >= 0) {
                        ret = min(ret, tmp + 1);
                    }
                }
                else {
                    tmpBoard.insert(pos_len[k][0], 1, hand[i]);
                    int tmp = findMinStep(tmpBoard, tmpHand);
                    if (tmp >= 0) {
                        ret = min(ret, tmp + 1);
                    }
                }
            }
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
