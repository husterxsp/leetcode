#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        if (n < 1) return ret;
        ret.push_back(1);

        int cur = 1;
        while (ret.size() < n) {
            while (cur <= n / 10) {
                cur *= 10;
                ret.push_back(cur);
            }
            cur++;
            while (cur % 10 == 0) cur /= 10;
            if (cur <= n) ret.push_back(cur);
        }

        return ret;
    }
};

int main() {
    Solution s = Solution();
    s.lexicalOrder(19);
    return 0;
}
