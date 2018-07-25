#include <iostream>
#include <vector>

using namespace std;

参考：
https://fisherlei.blogspot.tw/2012/12/leetcode-median-of-two-sorted-arrays.html
http://www.cnblogs.com/grandyang/p/4465932.html
int findK(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size(), n = nums2.size();
    if (m == 0) return nums2[k - 1];
    if (n == 0) return nums1[k - 1];
    if (k == 1) return min(nums1[0], nums2[0]);

    if (m/2 + n/2 + 1 >= k) {
        // 删除大的部分, k不变
        if (nums1[m/2] >= nums2[n/2]) {
            // 删除 nums1
            vector<int> tmpNums1 = vector<int>(nums1.begin(), nums1.begin() + m/2);
            return findK(tmpNums1, nums2, k);
        }
        else {
            vector<int> tmpNums2 = vector<int>(nums2.begin(), nums2.begin() + n/2);
            return findK(nums1, tmpNums2, k);
        }
    }
    else {
        // 删除小的部分，k变
        if (nums1[m/2] >= nums2[n/2]) {
            // 删除 nums2
            vector<int> tmpNums2 = vector<int>(nums2.begin() + n/2 + 1, nums2.end());
            return findK(nums1, tmpNums2, k - n/2 - 1);
        }
        else {
            vector<int> tmpNums1 = vector<int>(nums1.begin() + m/2 + 1, nums1.end());
            return findK(tmpNums1, nums2, k - m/2 - 1);
        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    if ((m + n) % 2 == 1) return findK(nums1, nums2, (m + n) / 2 + 1);

    return (findK(nums1, nums2, (m + n) / 2) + findK(nums1, nums2, (m + n) / 2 + 1)) / 2.0;
}


int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
