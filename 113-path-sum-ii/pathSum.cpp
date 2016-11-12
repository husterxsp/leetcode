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

vector<vector<int>> ret;
void getPathSum(TreeNode* root, int sum, vector<int> path) {
    if(!root) return;
    path.push_back(root->val);
    if(!root->left && !root->right) {
        if(sum == root->val){
            ret.push_back(path);
        };
        return;
    }
    if(root->left) getPathSum(root->left, sum-root->val, path);
    if(root->right) getPathSum(root->right, sum-root->val, path);
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<int> path;
    getPathSum(root, sum, path);
    return ret;
}

int main(){
    TreeNode * root = new TreeNode(1);
    TreeNode * node = new TreeNode(2);

    root->left = node;
    pathSum(root, 1);
}
