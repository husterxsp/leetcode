#include <iostream>
#include <vector>
#include <queue>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    root->left = node1;
    cout << maxDepth(root);
}
