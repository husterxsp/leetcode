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
    string tree2str(TreeNode* t) {
        if (!t) return "";
        string ret = to_string(t->val);
        if (t->left) ret += "(" + tree2str(t->left) + ")";
        if (!t->left && t->right) ret += "()";
        if (t->right) ret += "(" + tree2str(t->right) + ")";
        return ret;
    }
};
