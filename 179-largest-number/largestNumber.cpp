#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
/*
 简单的排序，类似桶排序和基数排序，这俩啥区别。。
 遇到的一点坑，bool强制转换，正负数都是转换为true的。。
 wrong answer: [121, 12]
 wrong answer: [0, 0]
 wrong answer: [824,938,1399,5607,6973,5703,9609,4398,8247]
 AC
 */
static bool mySort(string str1, string str2) {
    string s1 = str1 + str2;
    string s2 = str2 + str1;
    return s1 > s2;
}

string largestNumber(vector<int>& nums) {
    vector<vector<string>> arr(10);
    string ret = "";
    for (int i = 0; i < nums.size(); i++) {
        string str = to_string(nums[i]);
        int index = str[0] - '0';
        arr[index].push_back(str);
    }
    for (int i = 0; i < 10; i++) {
        sort(arr[i].begin(), arr[i].end(), mySort);
    }
    for (int i = 9; i >= 1; i--) {
        for (int j = 0; j < arr[i].size(); j++) {
            ret += arr[i][j];
        }
    }
    if (ret.length()) {
        for (int i = 0; i < arr[0].size(); i++) {
            ret += "0";
        }
    }
    else {
        ret += "0";
    }
    return ret;
}

int main () {
    vector<int> nums = {824,938,1399,5607,6973,5703,9609,4398,8247};
    cout << largestNumber(nums) << endl;
    return 0;
}
