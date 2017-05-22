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
    int search(TreeNode* root, bool left) {
        if (!root) return 0;
        if (!root->left && !root->right && left) return root->val;
        return search(root->left, 1) + search(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return search(root->left, 1) + search(root->right, 0);
    }
};
