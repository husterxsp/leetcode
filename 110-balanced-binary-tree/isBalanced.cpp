#include <iostream>
#include <vector>
#include <queue>
#include <Map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 这题写的太过复杂了啊。。。mdzz..
int depth(TreeNode* root){
    if(root == NULL) return 0;
    int dp = 1 + max(depth(root->left), depth(root->right));
    root->val = dp;
    return dp;
}
TreeNode* getDepth(TreeNode* root){
    root->val = 1 + max(depth(root->left), depth(root->right));
    return root;
}
bool balanced(TreeNode* root) {
    int left, right;
    if(root == NULL) return true;
    left = root->left ? root->left->val : 0;
    right = root->right ? root->right->val : 0;
    if(abs(left-right) > 1) return false;
    if(!balanced(root->left) || !balanced(root->right)) return false;
    return true;
}
bool isBalanced(TreeNode* root) {
    if(root == NULL) return true;
    root = getDepth(root);
    return balanced(root);
}

int main(){
    TreeNode * root = new TreeNode(0);
    TreeNode * node = new TreeNode(0);
    root->left = node;
    cout << isBalanced(root);
}
