#include <iostream>
#include <vector>
using namespace std;

// 相对于i,这题ii只是多加了一个变量来判断是否已经有两个相同的了
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;
    int len = 0;
    int hasTwo = false;
    for (int i = 1; i < n; i++) {
        if (nums[len] != nums[i]) {
            nums[++len] = nums[i];
            hasTwo = false;
        } else if(!hasTwo) {
            nums[++len] = nums[i];
            hasTwo = true;
        }
    }
    return len + 1;
}

int main() {
    vector<int> a = {1,1,1,2,2,3};
    cout << removeDuplicates(a);
    return 0;
}
