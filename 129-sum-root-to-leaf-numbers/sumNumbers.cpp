#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int ret = 0;
void DFS(TreeNode* root, int cur){
    if(!root) return;
    if(!root->left && !root->right) {
        ret += cur*10 + root->val;
        return;
    }
    DFS(root->left, cur*10+root->val);
    DFS(root->right, cur*10+root->val);
}
int sumNumbers(TreeNode* root) {
    if(!root) return 0;
    DFS(root, 0);
    return ret;
}

int main(){
    TreeNode* root =  new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    root->left = node1;
    root->right = node2;
    cout << sumNumbers(root);
    return 0;
}
