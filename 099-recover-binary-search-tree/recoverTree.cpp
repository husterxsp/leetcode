#include <iostream>
#include <vector>
#include <stack>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 先中序遍历再排序？
// 1. 基本有序情况下插入排序？
// 2. 看到网上的
void recoverTree(TreeNode* root) {
    stack<TreeNode*> myStack;
    TreeNode* save = NULL;
    TreeNode* p = root;
    TreeNode* lastNode = NULL;
    myStack.push(NULL);
    while (p) {
        if (p->left != lastNode) {
            while (p->left) {
                myStack.push(p);
                p = p->left;
            }
        }
        lastNode = p;
        if (!save) {
            save = p;
        }
        if (p->val > save->val) {
            save->val = p->val;
        }
        else {
            int tmp = save->val;
            save->val = p->val;
            p->val = tmp;
            save = p;
        }
        if (p->right) {
            p = p->right;
        }
        else {
            p = myStack.top();
            myStack.pop();
        }
    }
    cout << root->val;
}

int main () {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(0);
    root->right->right = new TreeNode(5);
    recoverTree(root);
    return 0;
}
