class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        for (int i = 0; i < len; i++) {
            if ((len - i) / 2 + 1 < n) return false;
            if (n == 0) return true;
            if (flowerbed[i] == 0) {
                if (i + 1 <= len - 1 && flowerbed[i + 1] == 1) continue;
                if (i - 1 >= 0 && flowerbed[i - 1] == 1) continue;
                flowerbed[i] = 1;
                i++;
                n--;
            }
        }
        return n == 0;
    }
};
