class Solution {
public:
    bool checkNum(string s) {
        if (s == "C" || s == "D" || s == "+" || s == "*") return false;
        return true;
    }
    int calPoints(vector<string>& ops) {
        int n = ops.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (ops[i] == "C") {
                for (int j = i - 1; j >= 0; j--) {
                    if (checkNum(ops[j])) {
                        sum -= stoi(ops[j]);
                        ops[j] = "*";
                        break;
                    }
                }
            }
            else if (ops[i] == "D") {
                for (int j = i - 1; j >= 0; j--) {
                    if (checkNum(ops[j])) {
                        ops[i] = to_string(2 * stoi(ops[j]));
                        sum += stoi(ops[i]);
                        break;
                    }
                }
            }
            else if (ops[i] == "+") {
                int round = 0, tmp = 0;
                for (int j = i - 1; j >= 0; j--) {
                    if (checkNum(ops[j])) {
                        tmp += stoi(ops[j]);
                        round++;
                    }
                    if (round == 2) {
                        sum += tmp;
                        ops[i] = to_string(tmp);
                        break;
                    }
                }
            }
            else {
                sum += stoi(ops[i]);
            }
        }
        return sum;
    }
};
