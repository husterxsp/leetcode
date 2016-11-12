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

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* p = root;
    TreeNode* lastNode = NULL;
    stack<TreeNode*> myStack;
    while (p || !myStack.empty()) {
        while (p) {
            myStack.push(p);
            p = p->left;
        }
        p = myStack.top();
        if(!p->right || p->right == lastNode){
            ret.push_back(p->val);
            lastNode = p;
            myStack.pop();
            p = NULL;
        } else {
            p = p->right;
        }
    }
    return ret;
}

int main(){
    TreeNode *head = new TreeNode(1);
    TreeNode *node = new TreeNode(2);
    node->right = new TreeNode(3);
    head->left = node;
    postorderTraversal(head);
    return 0;
}
