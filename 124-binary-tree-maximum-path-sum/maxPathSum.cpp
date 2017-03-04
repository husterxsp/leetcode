#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 思路：需要记录单边的最大值tmpMax，以及总和的最大值maxSum
// 另外注意传入的maxSum是地址，递归的过程中不断更新
int find(TreeNode* root, int& maxSum) {
    if (!root) {
        return 0;
    }
    int left = find(root->left, maxSum);
    int right = find(root->right, maxSum);
    int tmpMax = root->val;
    if (left > 0) {
        tmpMax += left;
    }
    if (right > 0) {
        tmpMax += right;
    }
    maxSum = max(tmpMax, maxSum);
    return max(root->val, max(root->val + left, root->val + right));
}

int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    return max(maxSum, find(root, maxSum));
}

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    cout << maxPathSum(root) << endl;
    return 0;
}
