/**
    参考：编程之美1.16
    对nums数组的复用很巧妙，计算完位置i,j，就覆盖掉这两个位置的值
*/
class Solution {
public:
    bool help(vector<double>& nums, int n) {
        if (n == 1) {
            if (abs(nums[0] - 24.0) < 0.001) {
                return true;
            }
            else return false;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a = nums[i], b = nums[j];
                nums[j] = nums[n - 1];

                nums[i] = a + b;
                if (help(nums, n - 1)) return true;

                nums[i] = a - b;
                if (help(nums, n - 1)) return true;

                nums[i] = b - a;
                if (help(nums, n - 1)) return true;

                nums[i] = a * b;
                if (help(nums, n - 1)) return true;

                if (a != 0) {
                    nums[i] = b / a;
                    if (help(nums, n - 1)) return true;
                }
                if (b != 0) {
                    nums[i] = a / b;
                    if (help(nums, n - 1)) return true;
                }

                nums[i] = a;
                nums[j] = b;
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& nums) {
        vector<double> tmp(4);
        for (int i = 0; i < 4; i++) tmp[i] = double(nums[i]);
        return help(tmp, 4);
    }
};
