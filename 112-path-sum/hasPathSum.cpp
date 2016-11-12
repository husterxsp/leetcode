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

bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;
    // 注意叶子节点的判断，另外就是注意节点值可能为负值。
    if(!root->left && !root->right) {
        if(sum == root->val) return true;
        return false;
    }
    if(root->left && root->right) return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum-root->val);
    if(root->left) return hasPathSum(root->left, sum - root->val);
    return hasPathSum(root->right, sum - root->val);
}

int main(){
    TreeNode * root = new TreeNode(1);
    TreeNode * node = new TreeNode(2);

    root->left = node;
    cout << hasPathSum(root, 1);
}
