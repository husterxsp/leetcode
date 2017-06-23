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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> vec;
        vec.push_back(root);
        while (1) {
            vector<TreeNode*> tmp;
            for (auto node : vec) {
                if (node->left) tmp.push_back(node->left);
                if (node->right) tmp.push_back(node->right);
            }
            if (tmp.empty()) return vec[0];
            vec = tmp;
        }
    }
};
