#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
/*
 解法1 二分查找，与No.378类似
 */
int searchLessEqual(vector<int>& nums1, vector<int>& nums2, int mid) {
    int m = nums1.size(), n = nums2.size();
    int ret = 0, i = n - 1, j = 0;
    while (i >= 0 && j < m) {
        if (nums1[j] + nums2[i] <= mid) {
            ret += i + 1;
            j++;
        }
        else {
            i--;
        }
    }
    return ret;
}
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int, int>> ret;
    int m = nums1.size(), n = nums2.size();
    if (!m || !n) return ret;

    int left = nums1[0] + nums2[0], right = nums1[m - 1] + nums2[n - 1];
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = searchLessEqual(nums1, nums2, mid);
        if (count >= k) right = mid;
        else left = mid + 1;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            pair<int, int> pair = {nums1[i], nums2[j]};
            int sum = nums1[i] + nums2[j];

            if (sum < left) ret.push_back(pair);
            else if (sum == left) ret.insert(ret.begin(), pair);
            else break;

            if (ret.size() > k) ret.erase(ret.begin(), ret.begin() + 1);
        }
    }

    return ret;
}

/*
 解法2 使用堆，自定义比较
 */

int main() {
    vector<int> nums1 = {1,2,4,5,6};
    vector<int> nums2 = {3,5,7,9};
    kSmallestPairs(nums1, nums2, 20);
    return 0;
}
