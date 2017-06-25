class Solution {
public:
    /**
        字符串包含问题，参考：https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.02.md
        位运算最优，时间复杂度O(n^2)
    */
    int maxProduct(vector<string>& words) {
        int n = words.size(), ret = 0;
        vector<int> hash(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < words[i].size(); j++) {
                hash[i] |= 1 << (words[i][j] - 'a');
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (!(hash[i] & hash[j])) {
                    ret = max(ret, (int)(words[i].size() * words[j].size()));
                }
            }
        }
        return ret;
    }
};
