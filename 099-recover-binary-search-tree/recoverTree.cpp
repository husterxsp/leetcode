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
// 难点在于中序遍历的空间复杂度
// 另外关于乱序的判断，
// ---大于右边或者小于左边---xxxx

void inOrder(TreeNode *root, vector<TreeNode*> &list, vector<int> &val) {
    if (root == null) return;
    inOrder(root->left, list, val);
    list.push_back(root);
    val.push_back(root->val);
    inOrder(root->right, list, val);
}
void recoverTree(TreeNode* root) {
    vector<TreeNode*> list;
    vector<int> val;
    inOrder(root, list, val);
    sort(val.begin(), val.end());
    for (int i = 0; i < list.size(); i++) {
        list[i]->val = val[i];
    }
}
// 待看：
// 非递归解法
// O(1)解法。

int main () {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(3);
    root->right = new TreeNode(1);
    recoverTree(root);
    return 0;
}
