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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *ret = new TreeNode(0);

        if (!t1) ret = t2;
        else if (!t2) ret = t1;
        else if (!t1 && !t2) return NULL;
        else {
            ret->val = t1->val + t2->val;
            ret->left = mergeTrees(t1->left, t2->left);
            ret->right = mergeTrees(t1->right, t2->right);
        }
        return ret;
    }
};
