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
    // 返回子树的节点sum
    int search(TreeNode* &root, int add) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            root->val += add;
            return root->val - add;
        }

        if (root->right) {
            root->val += search(root->right, add);
        }

        // if (root->left) root->left->val += root->val;
        if (!root->right) root->val += add;

        return root->val + search(root->left, root->val);
    }
    // 先访问右子树，再访问根节点，再访问左子树
    TreeNode* convertBST(TreeNode* root) {
        search(root, 0);
        return root;
    }

    // 非递归形式？
};
