/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
    思路：中序遍历
 */
class Solution {
public:
    void search(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        search(root->left, vec);
        vec.push_back(root->val);
        search(root->right, vec);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        search(root, vec);

        int ret = INT_MAX;
        for (int i = 0; i < n - 1; i++) {
            ret = min(ret, vec[i + 1] - vec[i]);
        }
        return ret;
    }
};
