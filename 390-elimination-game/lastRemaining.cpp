#include <iostream>

using namespace std;
class Solution {
public:
    /**
     注意边界条件啊喂！bug free啊喂！
     n = 1
     */
    int lastRemaining(int n) {
        int k = 1, gap = 1, ret = 1;
        while (n > 1) {
            int flag = k % 2 ? 1 : -1;

            n /=2;
            ret = ret + flag * (gap + 2 * gap * (n - 1));

            k++;
            gap *= 2;
        }
        return ret;
    }
};

/**
找规律，一步步分析，思路用last保存每次remove后剩下的数中的最后一个
last=1, 最后一个数
gap=1, 两个数之间的间隙
k=1, 第几层
k=1 , n=9 => n/2 -> n=4 -> last = last + gap + 2*gap*(n-1), last = 8
k=2 , n=4 => n/2 -> n=2 -> last = last - gap - 2*gap*(n-1), last = 2
k=3 , n=2 => n/2 -> n=1 -> last = last + gap + 2*gap*(n-1), last = 6
*/

int main() {
    Solution s = Solution();
    cout << s.lastRemaining(4) << '\n';
    return 0;
}
