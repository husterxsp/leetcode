class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'R') x++;
            else if (c == 'L') x--;
            else if (c == 'U') y++;
            else y--;
        }
        if (x == 0 && y == 0) return true;
        return false;
    }
};
