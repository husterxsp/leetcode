#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

/**
 解法1：
 尝试一点点处理。相等的时候的情况比较多。。
 超时。。。。
 实在无解
 */
using namespace std;
string search(vector<int> nums1, vector<int> nums2, int k) {
    int m = nums1.size(), n = nums2.size();

    string ret = "";
    if (k <= 0 || k > m + n) return ret;
    else if (k == m + n) {
        int i = 0, j = 0;
        while (i < m || j < n) {
            int num1 = i >= m ? -1 : nums1[i];
            int num2 = j >= n ? -1 : nums2[j];

            if (num1 == num2) {
                int i1 = i + 1, j1 = j + 1, minNum = num1;

                while (i1 < m && j1 < n && nums1[i1] == nums2[j1]) {
                    if (nums1[i1] < minNum) {
                        break;
                    }
                    else {
                        i1++;
                        j1++;
                    }
                    minNum = min(minNum, nums1[i1]);
                }
                string tmp = "";
                for (int k = i; k < i1; k++) {
                    tmp += to_string(nums1[k]);
                }
                if (i1 < m && j1 < n) {
                    if (nums1[i1] != nums2[j1]) {
                        ret += tmp;
                        if (nums1[i1] > nums2[j1]) i = i1;
                        else j = j1;
                    }
                    else {
                        ret += tmp + tmp;
                        i = i1;
                        j = j1;
                    }
                }
                else {
                    ret += tmp;
                    if (i1 >= m) j = j1;
                    else i = i1;
                }
            }
            else {
                ret += to_string(max(num1, num2));
                if (num1 > num2) i++;
                else j++;
            }
        }
    }
    else if (k < m + n) {
        priority_queue<int> q1, q2;
        int maxNum1 = 0, maxIndex1 = 0, maxNum2 = 0, maxIndex2 = 0;
        for (int i = 0; i < m && i <= m + n - k; i++) {
            if (nums1[i] > maxNum1) {
                maxIndex1 = i;
                maxNum1 = nums1[i];
            }
            q1.push(nums1[i]);
        }
        for (int i = 0; i < n && i <= m + n - k; i++) {
            if (nums2[i] > maxNum2) {
                maxIndex2 = i;
                maxNum2 = nums2[i];
            }
            q2.push(nums2[i]);
        }

        if (maxNum1 == maxNum2) {
            ret = to_string(maxNum1);
            vector<int> v1(nums1.begin() + maxIndex1 + 1, nums1.end());
            vector<int> v2(nums2.begin() + maxIndex2 + 1, nums2.end());

            string str1 = search(v1, nums2, k - 1);
            string str2 = search(nums1, v2, k - 1);

            if (str1 > str2) ret += str1;
            else ret += str2;
        }
        else if (maxNum1 > maxNum2) {
            ret = to_string(maxNum1);

            vector<int> v(nums1.begin() + maxIndex1 + 1, nums1.end());

            ret += search(v, nums2, k - 1);
        }
        else {
            ret = to_string(maxNum2);

            vector<int> v(nums2.begin() + maxIndex2 + 1, nums2.end());

            ret += search(nums1, v, k - 1);
        }
    }
    return ret;
}
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ret;

    string retStr = search(nums1, nums2, k);
    for (int i = 0; i< retStr.size(); i++) {
        ret.push_back(retStr[i] - '0');
    }
    return ret;
}

int main() {
    vector<int> num1 = {1,0,1,0,3,9,1,2,8};
    vector<int> num2 = {6,0,5,0};
    maxNumber(num1, num2, 13);
    return 0;
}
