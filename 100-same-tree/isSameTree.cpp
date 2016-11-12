#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 比较简单
bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL){
        return true;
    }
    if(p && q && p->val == q->val){
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}

int main()
{
    struct TreeNode* root = new TreeNode(2);
    struct TreeNode* node1 = new TreeNode(3);
    struct TreeNode* node2 = new TreeNode(1);
    
    root->left = node1;
    node1->left = node2;
    isSameTree(node1, node2);
    return 0;
}