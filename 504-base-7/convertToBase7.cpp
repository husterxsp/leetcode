class Solution {
public:
    // 注意边界条件
    string convertToBase7(int num) {
        string ret = "";
        int flag = num < 0 ? -1 : 1;
        num = abs(num);
        while (num != 0) {
            ret = to_string(num % 7) + ret;
            num /= 7;
        }

        ret = flag == -1 ? "-" + ret : ret;
        ret = ret.size() == 0 ? "0" : ret;
        return ret;
    }
};
