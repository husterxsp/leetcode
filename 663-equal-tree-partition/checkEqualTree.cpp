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
    bool search(TreeNode* root, int target) {
        if (!root) return false;
        if (root->val == target) return true;

        return search(root->left, target) || search(root->right, target);
    }
    int sum(TreeNode* &root) {
        if (!root) return 0;
        return root->val += sum(root->left) + sum(root->right);
    }
    bool checkEqualTree(TreeNode* root) {
        if (!root) return false;
        if (!root->left && !root->right) return false;

        sum(root);
        if (root->val % 2 != 0) return false;
        return search(root, root->val / 2);
    }
};
