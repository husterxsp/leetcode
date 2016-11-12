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

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ret;
    TreeNode* p = root;
    vector<TreeNode*> stack = {NULL};
    while (p) {
        ret.push_back(p->val);
        if(p->right){
            stack.push_back(p->right);
        }
        if(p->left){
            p = p->left;
        }else {
            p = stack.back();
            stack.pop_back();
        }
    }
    return ret;
}

int main(){
    TreeNode *head = new TreeNode(1);
    TreeNode *node = new TreeNode(2);
    head->left = node;
    preorderTraversal(head);
    return 0;
}
