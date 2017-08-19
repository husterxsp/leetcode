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
    后序遍历
 */
 class Solution {
 public:
     void postorderTraversal(TreeNode* &root, int& sum) {
         if (!root) return;
         postorderTraversal(root->right, sum);
         root->val += sum;
         sum = root->val;
         postorderTraversal(root->left, sum);
     }
     TreeNode* convertBST(TreeNode* root) {
         int sum = 0;
         postorderTraversal(root, sum);
         return root;
     }
 };
