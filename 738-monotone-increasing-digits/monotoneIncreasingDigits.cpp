class Solution {
public:
    int monotoneIncreasingDigits(int N) {

        if (N < 10) return N;

        string str = to_string(N);
        int i = 1;
        for (i = 1; i < str.size(); i++) {
            if (str[i - 1] > str[i]) {
                str[i - 1] -= 1;
                break;
            }
        }
        for (; i < str.size(); i++) {
            str[i] = '9';
        }
        return stoi(str);
    }
};
