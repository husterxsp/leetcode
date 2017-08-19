/**
    先二分找到中点
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int mid = 0, left = 0, right = n;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            if (arr[mid] == x) break;
            else if (arr[mid] > x) right = mid;
            else left = mid;
        }

        left = mid - 1, right = mid;
        vector<int> ret;
        while (ret.size() < k) {
            if (left < 0) ret.push_back(arr[right++]);
            else if (right >= n) ret.insert(ret.begin(), arr[left--]);
            else if (x - arr[left] <= arr[right] - x) ret.insert(ret.begin(), arr[left--]);
            else ret.push_back(arr[right++]);
        }
        return ret;
    }
};
