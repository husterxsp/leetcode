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
    bool isSametree(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        else if (!s || !t) return false;
        else if (s->val != t->val) return false;

        return isSametree(s->left, t->left) && isSametree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        if (s->val == t->val && isSametree(s->left, t->left) && isSametree(s->right, t->right)) return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
