#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

/**
    参考：http://www.cnblogs.com/grandyang/p/5727892.html
    解法1，使用堆
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<int> myQueue;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            myQueue.push(matrix[i][j]);
            if (myQueue.size() > k) myQueue.pop();
        }
    }

    return myQueue.top();
}

/**
解法2，这个时间复杂度怎么算？??
*/
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = 0;
        for (auto row : matrix) {
            count += upper_bound(row.begin(), row.end(), mid) - row.begin();
        }
        // 注意此处count=k的情况，count既然等于k，那应该保存这个结果
        // 如果等于k,还用left = mid + 1的条件可能就错过这个mid了。
        if (count >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}

/**
解法3，对解法2的优化
*/
int searchLessEqual(vector<vector<int>>& matrix, int mid) {
    int ret = 0, n = matrix.size(), i = n - 1, j = 0;
    while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) {
            ret += i + 1;
            j++;
        }
        else {
            i--;
        }
    }

    return ret;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left < right) {
        int mid = left + (right - left) / 2;
        int count = searchLessEqual(matrix, mid);
        if (count >= k) right = mid;
        else left = mid + 1;
    }
    return left;
}


int main() {
    vector<vector<int>> matrix = {
        {1,5,9},
        {10,11,13},
        {12,13,15},
    };
    cout << kthSmallest(matrix, 5) << endl;
    return 0;
}
