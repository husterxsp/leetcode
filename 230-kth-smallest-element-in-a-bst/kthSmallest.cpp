#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 简单的中序遍历。。。
int kthSmallest(TreeNode* root, int k) {
    int ret = 0, cur = 0;

    stack<TreeNode*> nodeStack;
    while (root) {
        while (root->left) {
            nodeStack.push(root);
            root = root->left;
        }
        if (++cur == k) return root->val;
        if (root->right) {
            root = root->right;
        }
        else {
            root = nodeStack.top();
            root->left = NULL;
            nodeStack.pop();
        }
    }
    return ret;
}

int main () {
/**
        10
       /
      7
     /
    4
   /
  1
   \
    3
   /
  2
*/
    TreeNode* root = new TreeNode(10);
    TreeNode* node1 = new TreeNode(7);
    TreeNode* node2 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(2);
    root->left = node1;
    node1->left = node2;
    node2->left = node3;
    node3->left = node4;

    cout << kthSmallest(root, 3) << endl;
    return 0;
}
