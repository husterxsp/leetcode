/**
    调整成 kx = n
    pos=1表示当前在=左边，-1表示在=右边
    symbol=-1表示前一个字符为-
*/
class Solution {
public:
    string solveEquation(string equation) {
        int pos = 1, symbol = 1, len = equation.size(), k = 0, n = 0;
        for (int i = 0; i < len; i++) {
            if (equation[i] == '=') pos = -1;
            // +, -, num, num * x
            else if (equation[i] == '+') continue;
            else if (equation[i] == '-') symbol = -1;
            else {
                int cur = 0;
                while (equation[i] >= '0' && equation[i] <= '9') {
                    cur = cur * 10 + equation[i] - '0';
                    i++;
                }
                if (equation[i] == 'x') {
                    if (cur == 0) {
                        if (i == 0 || (i > 0 && equation[i - 1] != '0')) cur = 1;
                    }
                    k += cur * symbol * pos;
                }
                else {
                    n -= cur * symbol * pos;
                    i--;
                }
                symbol = 1;
            }
        }
        if (k == 0) {
            if (n == 0) return "Infinite solutions";
            else return "No solution";
        }
        return "x=" + to_string(n / k);
    }
};
