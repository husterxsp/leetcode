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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if (!root) return ret;
        vector<TreeNode*> vec{root};
        while (!vec.empty()) {
            double sum = 0;
            vector<TreeNode*> tmp;
            for (auto v : vec) {
                sum += v->val;
                if (v->left) tmp.push_back(v->left);
                if (v->right) tmp.push_back(v->right);
            }
            ret.push_back(sum / vec.size());
            vec = tmp;
        }
        return ret;
    }
};
