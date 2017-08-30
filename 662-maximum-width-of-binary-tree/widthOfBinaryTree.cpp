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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode*> q;
        int ret = 0, len = 0;
        q.push_back(root);

        while (q.size()) {
            ret = max(ret, (int)q.size());
            deque<TreeNode*> tmp;
            len = q.size();

            for (int i = 0; i < len; i++) {
                TreeNode* v = q.front();
                q.pop_front();
                if (!v) {
                    tmp.push_back(NULL);
                    tmp.push_back(NULL);
                }
                else {
                    tmp.push_back(v->left);
                    tmp.push_back(v->right);
                }
            }
            len = tmp.size();
            for (int i = 0; i < len; i++) {
                if (tmp.front() == NULL) tmp.pop_front();
            }
            len = tmp.size();
            for (int i = len; i > 0; i--) {
                if (tmp.back() == NULL) tmp.pop_back();
            }
            q = tmp;
        }
        return ret;
    }
};
