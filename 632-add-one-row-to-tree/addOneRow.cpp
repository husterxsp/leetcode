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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return root;
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;

        int curD = 0;
        vector<TreeNode*> vec;
        vec.push_back(dummy);
        while (vec.size() && curD++ < d - 1) {
            vector<TreeNode*> tmp;
            for (auto node : vec) {
                if (node->left) tmp.push_back(node->left);
                if (node->right) tmp.push_back(node->right);
            }
            vec = tmp;
        }

        for (auto node : vec) {
            TreeNode* tmp = node->left;
            node->left = new TreeNode(v);
            node->left->left = tmp;

            tmp = node->right;
            node->right = new TreeNode(v);
            node->right->right = tmp;
        }
        return dummy->left;
    }
};
