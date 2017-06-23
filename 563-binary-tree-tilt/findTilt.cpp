/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /**
        思路：递归求子树的和，在求和的过程中计算左右子树差值。
    */
    int sum(TreeNode* root, int &ret) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;

        int left = sum(root->left, ret);
        int right = sum(root->right, ret);
        ret += abs(left - right);

        return root->val + left + right;
    }
    int findTilt(TreeNode* root) {
        int ret = 0;
        sum(root, ret);
        return ret;
    }
};
