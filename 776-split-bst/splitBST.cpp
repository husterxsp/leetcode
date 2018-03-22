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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        vector<TreeNode*> ret(2, NULL);
        if (!root) return ret;

        int preLeft = 1;
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;

        TreeNode* cur = dummy->left, * pre = dummy;
        while (cur) {
            if (cur->val == V) {

                if (preLeft) pre->left = cur->right;
                else pre->right = cur->right;

                cur->right = NULL;

                ret[0] = cur;

                ret[1] = dummy->left;
                break;
            }
            else if (cur->val > V) {
                pre = cur;
                preLeft = 1;
                cur = cur->left;
            }
            else {

                vector<TreeNode*> tmp = splitBST(cur->right, V);

                if (preLeft) {
                    pre->left = tmp[1];
                }
                else {
                    pre->right = tmp[1];
                }
                cur->right = tmp[0];
                ret[0] = cur;

                ret[1] = dummy->left;

                break;
            }
        }
        if (!ret[1] && !ret[0]) ret[1] = root;
        return ret;
    }
};
