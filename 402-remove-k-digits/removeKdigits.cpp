/**
解法1：
总提示 "222222222222222222222210" 12  Status: Memory Limit Exceeded  无法理解
*/
class Solution {
public:
    string delZero(string num) {
        int i = 0;
        while (i < num.size() && num[i] == '0') i++;
        return num.substr(i, num.size() - i);
    }
    string help(string num, int k, int pos) {
        if (num.size() <= k) return "0";
        if (k == 0) return num;

        // del表示待删除部分长度
        int i = 0, del = 1;
        for (i = pos; i < num.size() - 1; i++) {
            if (num[i] < num[i + 1]) continue;
            if (num[i] == num[i + 1]) {
                int tmpI = i;
                while (tmpI < num.size() - 1 && num[tmpI] == num[tmpI + 1]) tmpI++;

                if (tmpI == num.size() - 1 || num[tmpI] > num[tmpI + 1]) del = min(k, tmpI - i + 1);
                else i = tmpI + 1;
            }
            break;
        }

        num = num.substr(0, i) + num.substr(i + del, num.size() - i - del);

        return help(delZero(num), k - del, max(i - 1, 0));
    }
    string removeKdigits(string num, int k) {
        return help(num, k, 0);
    }
};

/**
    确实写得更简洁一些。。但整体思路还是差不多的。。。
*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ret = "";
        int n = num.size(), keep = n - k;
        for (c : num) {
            while (k && ret.size() && ret.back() > c) {
                ret.pop_back();
                k--;
            }
            ret.push_back(c);
        }
        ret.resize(keep);

        while (!ret.empty() && ret[0] == '0') ret.erase(ret.begin());
        return ret.empty() ? "0" : ret;
    }
};
