#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 递归解
bool isEqualTree(TreeNode* left, TreeNode* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->val != right->val) return false;
    
    return isEqualTree(left->left, right->right)
        && isEqualTree(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
    if(root == NULL){
        return true;
    }
    return isEqualTree(root->left, root->right);
}
// 非递归解
