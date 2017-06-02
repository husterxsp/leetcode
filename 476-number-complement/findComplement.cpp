class Solution {
public:
    int findComplement(int num) {
        bitset<32> b(num);
        int mask = 1, count = b.count();

        while (count > 0) {
            if (num & mask) count--;
            num ^= mask;
            mask <<= 1;
        }
        return num;
    }
};
