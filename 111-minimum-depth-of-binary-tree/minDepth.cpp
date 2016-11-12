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
// 注意叶子节点的判断就好
int depth(TreeNode* root){
    if(!root->left && !root->right) return 1;
    if(root->left && root->right) return 1 + min(depth(root->left), depth(root->right));
    if(root->left != NULL) return 1 + depth(root->left);
    return 1 + depth(root->right);
}
int minDepth(TreeNode* root){
    if(root == NULL) return 0;
    return depth(root);
}

int main(){
    TreeNode * root = new TreeNode(1);
    TreeNode * node = new TreeNode(2);
    TreeNode * node2 = new TreeNode(3);
    TreeNode * node3 = new TreeNode(4);
    TreeNode * node4 = new TreeNode(5);
    root->left = node;
    root->right = node2;
    node->left = node3;
    node->right = node4;
    cout << minDepth(root);
}
