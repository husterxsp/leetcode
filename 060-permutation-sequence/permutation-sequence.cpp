#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 思路：
// 1. 递归回溯，添加标志位
// 2. 数学解
string getPermutation(int n, int k) {
    vector<int> nums(n);
    int perm = 1;
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
        perm *= nums[i];
    }
    string ret = "";
    k--;
    for (int i = 0; i < n; i++) {
        perm /= n - i;
        int choosed = k / perm;
        ret += nums[choosed] + '0';
        for (int j = choosed; j < n - i; j++)   {
            nums[j] = nums[j + 1];
        }
        k %= perm;
    }
    return ret;
}

int main(){
    cout << getPermutation(3, 1);
    return 0;
}
