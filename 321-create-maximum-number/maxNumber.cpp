#include <iostream>
#include <vector>

/**
    没能AC
    {3, 9}
    {8, 9}
*/
using namespace std;
vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<int> ret;

    int m = (int)nums1.size();
    int n = (int)nums2.size();

    if (k <= 0) return ret;
    if (k == m + n) {
        int flag = 1;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                flag = 2;
                break;
            }
            else if (nums1[i] > nums2[j]) {
                break;
            }
            else {
                i = ++i % m;
                j = ++j % n;
            }
        }
        if (flag == 1) {
            ret.insert(ret.end(), nums1.begin(), nums1.end());
            ret.insert(ret.end(), nums2.begin(), nums2.end());
        }
        else {
            ret.insert(ret.end(), nums2.begin(), nums2.end());
            ret.insert(ret.end(), nums1.begin(), nums1.end());
        }
        return ret;
    }

    int slide = m + n - k;
    int maxFirst = 0;
    int pos = 0;
    int posArr = 1;

    for (int i = 0; i < m && i <= slide; i++) {
        if (nums1[i] > maxFirst) {
            maxFirst = nums1[i];
            pos = i;
        }
    }
    for (int i = 0; i < n && i <= slide; i++) {
        if (nums2[i] > maxFirst) {
            maxFirst = nums2[i];
            pos = i;
            posArr = 2;
        }
    }

    if (posArr == 1) {
        nums1.erase(nums1.begin(), nums1.begin() + pos + 1);
    }
    else {
        nums2.erase(nums2.begin(), nums2.begin() + pos + 1);
    }

    ret.push_back(maxFirst);
    vector<int> recur = maxNumber(nums1, nums2, k - 1);
    ret.insert(ret.end(), recur.begin(), recur.end());

    return ret;
}

int main() {
    vector<int> num1 = {8,9};
    vector<int> num2 = {3,9};
    maxNumber(num1, num2, 3);
    return 0;
}
