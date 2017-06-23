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
    // 这题也可忽略。。
    vector<int> largestValues(TreeNode* root) {
        vector<TreeNode*> vec;
        vector<int> ret;
        if (!root) return ret;

        vec.push_back(root);
        while (!vec.empty()) {
            vector<TreeNode*> tmp;
            int max_value = INT_MIN;
            for (auto node : vec) {
                max_value = max(max_value, node->val);
                if (node->left) tmp.push_back(node->left);
                if (node->right) tmp.push_back(node->right);
            }
            ret.push_back(max_value);
            vec = tmp;
        }
        return ret;
    }
};
