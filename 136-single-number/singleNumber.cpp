#include <iostream>
#include <vector>
#include <map>

using namespace std;
//解法一：hash, O(n)时间，O(n)空间
//解法二：排序，O(nlogn)时间，快排
int singleNumber(vector<int>& nums) {
    map<int, int> myMap;
    int n = nums.size();
    int ret;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (myMap.count(num) > 0) {
            myMap[num] = 2;
        }
        else {
            myMap[num] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (myMap[num] == 1) {
            ret = num;
        }
    }
    return ret;
}
//终极解法：位运算
int singleNumber(vector<int>nums) {
    int res = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++)
        res ^= nums[i];
    return res;
}

int main(){
    vector<int> arr = {1, 1, 2, 2, 1111111};
    cout << singleNumber(arr) << endl;
    return 0;
}
