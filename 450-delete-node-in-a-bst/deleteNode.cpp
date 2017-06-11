#include <iostream>
#include <vector>
#include <Map>
#include <Set>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return NULL;

    if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else {
        // 与右子树的最小值交换，并删除节点；或者与左子树的最大值交换并删除节点。
        // 这部分关于指针的处理有待继续看啊。。
        if (root->right) {
            TreeNode* p = root->right;
            while (p->left) p = p->left;
            root->val = p->val;
            root->right = deleteNode(root->right, p->val);
        }
        else {
            root = root->left;
        }
    }
    return root;
}
/**
 4
 /   \
 2     5
 / \     \
 1   3      6
 */
int main () {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node4->left = node2;
    node4->right = node5;

//    node2->left = node1;
    node2->right = node3;

    node5->right = node6;

    TreeNode* p = node4->left;
    p = p->right;


//    deleteNode(node4, 2);
    return 0;
}
