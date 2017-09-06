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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) return NULL;

        TreeNode* ret = root;

        if (ret->val > R) {
            ret = ret->left;
            return trimBST(ret, L, R);
        }
        else if (ret->val < L) {
            ret = ret->right;
            return trimBST(ret, L, R);
        }

        ret->left = trimBST(ret->left, L, R);
        ret->right = trimBST(ret->right, L, R);
        return ret;
    }
};
