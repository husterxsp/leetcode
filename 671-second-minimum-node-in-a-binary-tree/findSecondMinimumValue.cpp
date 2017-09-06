/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
    思路一：直接暴力把所有节点的值放进set
    思路二：从根节点遍历，应该只用遍历子树中，子节点值比根节点大的子树
 */
class Solution {
public:
    void help(TreeNode* root, set<int>& mySet) {
        if (root) {
            mySet.insert(root->val);

            help(root->left, mySet);
            help(root->right, mySet);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> mySet;
        help(root, mySet);
        if (mySet.size() < 2) return -1;

        return *next(mySet.begin(), 1);
    }
};
