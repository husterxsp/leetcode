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
    void inorderTraversal(TreeNode *root, vector<int> &arr) {
        if (root->left) inorderTraversal(root->left, arr);
        if (root) arr.push_back(root->val);
        if (root->right) inorderTraversal(root->right, arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorderTraversal(root, arr);

        unordered_set<int> mySet(arr.begin(), arr.end());
        for (int num : arr) {
            // 注意这里用乘法，除法的话注意除2的时候取整的问题
            if (num * 2 >= k) break;
            if (mySet.find(k - num) != mySet.end()) return true;
        }
        return false;
    }
};
