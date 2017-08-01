/**
    解法1：暴力求解超时
*/
class Solution {
public:
    bool check(vector<int> v) {
        return v[0] + v[1] > v[2] && v[0] + v[2] > v[1] && v[1] + v[2] > v[0];
    }
    void search(vector<int>& nums, int pos, vector<int>& cur, int &ret) {
        if (cur.size() == 3) {
            if (check(cur)) ret++;
            return;
        }

        for (int i = pos; i < nums.size(); i++) {
            if (cur.size() == 2) {
                if (cur[0] + cur[1] < nums[i]) break;
            }
            cur.push_back(nums[i]);
            search(nums, i + 1, cur, ret);
            cur.pop_back();
        }
    }
    int triangleNumber(vector<int>& nums) {
        int ret = 0;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        search(nums, 0, cur, ret);

        return ret;
    }
};
/**
    解法2：二分查找。先确定两个数，再二分查找第三个数
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // 此处right应初始化为n, 如果初始化为n-1, 则right - j - 1 可能是个负数
                // right 表示第一个大于等于 sum 的位置
                int left = j + 1, right = n, sum = nums[i] + nums[j];
                while (left < right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) left = mid + 1;
                    else right = mid;
                }
                ret += right - j - 1;
            }
        }
        return ret;
    }
};

/**
    解法3：两个指针从两边查找
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int ret = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 2; i < n; i++) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    ret += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ret;
    }
};
