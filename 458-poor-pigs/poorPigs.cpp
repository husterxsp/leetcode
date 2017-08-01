/**
    一开始的错误想法：有几只pig就将bucket均分为几份。。
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie + 1;
        ret = 0;
        while (pow(ret, times) < buckets) ret++;
        return ret;
    }
};
