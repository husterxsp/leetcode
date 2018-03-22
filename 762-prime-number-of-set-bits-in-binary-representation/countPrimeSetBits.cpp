// easy
class Solution {
public:
    bool checkPrime(int n) {
        if (n == 1) return false;
        for(int i = 2; i <= n / 2; i++) {
            if(n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int ret = 0;
        for (int i = L; i <= R; i++) {
            bitset<32> myBit(i);
            if (checkPrime(myBit.count())) ret++;
        }
        return ret;
    }
};
