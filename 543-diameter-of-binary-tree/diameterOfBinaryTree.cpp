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
    // 返回树的深度depth
    int depth(TreeNode* root, int &ret) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int left = depth(root->left, ret);
        int right = depth(root->right, ret);
        ret = max(ret, left + right);
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ret = 0;
        depth(root, ret);
        return ret;
    }
};
