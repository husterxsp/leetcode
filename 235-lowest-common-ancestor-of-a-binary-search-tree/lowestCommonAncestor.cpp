#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);;
    return root;
}
/**
        6
      /  \
     2    8
    / \   / \
   0   4 7   9
*/
int main () {

    TreeNode* node1 = new TreeNode(6);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(8);
    TreeNode* node4 = new TreeNode(0);
    TreeNode* node5 = new TreeNode(4);
    TreeNode* node6 = new TreeNode(7);
    TreeNode* node7 = new TreeNode(9);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;

    cout << lowestCommonAncestor(node1, node5, node1)->val << endl;
    return 0;
}
