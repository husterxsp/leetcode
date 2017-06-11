class Solution {
public:
    // 什么鬼。。。大概是找规律
    // 参考：https://www.liuchuo.net/archives/3087
    int magicalString(int n) {
        string s = "122";
        for (int i = 2; s.size() < n; i++) {
            int count = s[i] - '0';
            char c = s.back() == '1' ? '2' : '1';
            string tmp(count, c);
            s += tmp;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};
