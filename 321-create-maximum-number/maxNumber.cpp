#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>


using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {

    auto cmp = [](pair<int, int> const & a, pair<int, int> const & b) {
        return a.first != b.first ? a.first > b.first : a.second < b.second;
    };

    vector<pair<int, int>> v1, v2;
    int m = nums1.size(), n = nums2.size();

    for (int i = 0; i < m; i++) v1.push_back({nums1[i], i});
    for (int i = 0; i < n; i++) v2.push_back({nums2[i], i});

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);

    vector<int> ret;

    int index1 = 0, index2 = 0;
    while (k > 0) {
        int p1 = 0, p2 = 0;
        while (1) {
            if (m - v1[p1].second + n - v2[p2].second == k) {
                if (v1[p1].first > v2[p2].first) ret.push_back(v1[p1].first);
                else ret.push_back(v2[p1].first);

                k--;
                break;
            }
            else if (m - v1[p1].second + n - v2[p2].second > k) {

            }

            if (v1[p1].first > v2[p2].first) {
                if (m - v1[p1].second + n - v2[p2].second >= k) {
                    ret.push_back(v1[p1].first);
                    v1.erase(v1.begin() + k1);
                    index1 = v1[p1].second;
                }
                else {

                }
            }
            else {
                ret.push_back(v2[p1].first);
            }
        }
    }

    return ret;
}
int main() {
    vector<int> num1 = {1,0,1,0,3,9,1,2,8};
    vector<int> num2 = {6,0,5,0};
    maxNumber(num1, num2, 13);
    return 0;
}

// class Solution {
// public:
//     string search(vector<int> nums1, vector<int> nums2, int k, vector<vector<vector<string>>>& dp) {
//         int m = nums1.size(), n = nums2.size();
//
//         if (dp[k][m][n] != "") return dp[k][m][n];
//
//         string ret = "";
//         if (k <= 0) return ret;
//         else if (k == m + n) {
//             int i = 0, j = 0;
//             while (i < m || j < n) {
//                 int num1 = i >= m ? -1 : nums1[i];
//                 int num2 = j >= n ? -1 : nums2[j];
//
//                 if (num1 == num2) {
//                     int i1 = i + 1, j1 = j + 1, minNum = num1;
//
//                     while (i1 < m && j1 < n && nums1[i1] == nums2[j1]) {
//                         if (nums1[i1] < minNum) {
//                             break;
//                         }
//                         else {
//                             i1++;
//                             j1++;
//                         }
//                         minNum = min(minNum, nums1[i1]);
//                     }
//                     string tmp = "";
//                     for (int k = i; k < i1; k++) {
//                         tmp += to_string(nums1[k]);
//                     }
//                     if (i1 < m && j1 < n) {
//                         if (nums1[i1] != nums2[j1]) {
//                             ret += tmp;
//                             if (nums1[i1] > nums2[j1]) i = i1;
//                             else j = j1;
//                         }
//                         else {
//                             ret += tmp + tmp;
//                             i = i1;
//                             j = j1;
//                         }
//                     }
//                     else {
//                         ret += tmp;
//                         if (i1 >= m) j = j1;
//                         else i = i1;
//                     }
//                 }
//                 else {
//                     ret += to_string(max(num1, num2));
//                     if (num1 > num2) i++;
//                     else j++;
//                 }
//             }
//         }
//         else if (k < m + n) {
//             priority_queue<int> q1, q2;
//             int maxNum1 = 0, maxIndex1 = 0, maxNum2 = 0, maxIndex2 = 0;
//             for (int i = 0; i < m && i <= m + n - k; i++) {
//                 if (nums1[i] > maxNum1) {
//                     maxIndex1 = i;
//                     maxNum1 = nums1[i];
//                 }
//                 q1.push(nums1[i]);
//             }
//             for (int i = 0; i < n && i <= m + n - k; i++) {
//                 if (nums2[i] > maxNum2) {
//                     maxIndex2 = i;
//                     maxNum2 = nums2[i];
//                 }
//                 q2.push(nums2[i]);
//             }
//
//             if (maxNum1 == maxNum2) {
//                 ret = to_string(maxNum1);
//                 vector<int> v1(nums1.begin() + maxIndex1 + 1, nums1.end());
//                 vector<int> v2(nums2.begin() + maxIndex2 + 1, nums2.end());
//
//                 string str1 = search(v1, nums2, k - 1, dp);
//                 string str2 = search(nums1, v2, k - 1, dp);
//
//                 if (str1 > str2) ret += str1;
//                 else ret += str2;
//             }
//             else if (maxNum1 > maxNum2) {
//                 ret = to_string(maxNum1);
//
//                 vector<int> v(nums1.begin() + maxIndex1 + 1, nums1.end());
//
//                 ret += search(v, nums2, k - 1, dp);
//             }
//             else {
//                 ret = to_string(maxNum2);
//
//                 vector<int> v(nums2.begin() + maxIndex2 + 1, nums2.end());
//
//                 ret += search(nums1, v, k - 1, dp);
//             }
//         }
//         return dp[k][m][n] = ret;
//     }
//     vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<int> ret;
//
//         vector<vector<vector<string>>> dp(k + 1, vector<vector<string>>(nums1.size() + 1, vector<string>(nums2.size() + 1)));
//
//         string retStr = search(nums1, nums2, k, dp);
//         for (int i = 0; i< retStr.size(); i++) {
//             ret.push_back(retStr[i] - '0');
//         }
//         return ret;
//     }
//
// };
