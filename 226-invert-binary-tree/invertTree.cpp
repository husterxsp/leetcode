#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (!root) return root;

    TreeNode* tmpLeft = invertTree(root->left);
    TreeNode* tmpRight = invertTree(root->right);

    root->left = tmpRight;
    root->right = tmpLeft;
    return root;
}

int main () {
    TreeNode* root = new TreeNode(1);
    TreeNode* left = new TreeNode(2);
    TreeNode* right = new TreeNode(3);
    root->left = left;
    root->right = right;
    invertTree(root);
    return 0;
}
