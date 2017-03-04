#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
 思路：层序遍历
    1
  /  \
 2    3
 \    \
 5    4
 /
 6
 */
vector<int> rightSideView(TreeNode* root) {
    queue<TreeNode*> traverse;
    vector<int> ret;
    if (!root) return ret;
    traverse.push(root);
    while (!traverse.empty()) {
        int size = traverse.size();
        ret.push_back(traverse.back()->val);

        for (int i = 0; i < size; i++) {
            TreeNode* p = traverse.front();
            traverse.pop();
            if (p->left) traverse.push(p->left);
            if (p->right) traverse.push(p->right);
        }
    }
    return ret;
}

int main () {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node1->left = node2;
    node1->right = node3;
    node2->right = node5;
    node3->right = node4;
    node5->left = node6;
    rightSideView(NULL);
    return 0;
}
