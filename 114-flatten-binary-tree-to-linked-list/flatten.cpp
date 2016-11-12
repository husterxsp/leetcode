#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 先序遍历
void flatten(TreeNode* root) {
    vector<TreeNode*> stack;
    if(root == NULL) return;
    TreeNode * p = root;
    stack.push_back(NULL);
    while (p || !stack.empty()) {
        if(p->right) {
            stack.push_back(p->right);
        }
        if(p->left){
            p->right = p->left;
            p->left = NULL;
            p = p->right;
        } else {
            p->right = stack.back();
            p = p->right;
            stack.pop_back();
        }
    }
}

int main(){
    TreeNode* root = new TreeNode(3);
    TreeNode* node = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(4);
    root->right = node3;
    root->left = node;
    node->right = node2;
    flatten(root);
    return 0;
}
