class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ret = "";
        for (auto c : S) if (c != '-') ret += toupper(c);

        int n = ret.size();
        for (int i = n - K; i > 0; i -= K) {
            ret.insert(ret.begin() + i, '-');
        }
        return ret;
    }
};
