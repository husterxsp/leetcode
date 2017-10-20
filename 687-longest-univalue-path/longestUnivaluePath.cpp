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
    int dfs(TreeNode* root, TreeNode* last, int& ret) {
        if (!root) return 0;

        int left = 0, right = 0;
        if (root->left) {
            if (root->val == root->left->val) left++;
            left += dfs(root->left, root, ret);
        }

        if (root->right) {
            if (root->val == root->right->val) right++;
            right += dfs(root->right, root, ret);
        }

        ret = max(ret, left + right);
        if (last && last->val == root->val) return max(left, right);

        return 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        dfs(root, NULL, ret);
        return ret;
    }
};
