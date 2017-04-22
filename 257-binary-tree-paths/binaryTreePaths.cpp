#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    if (!root) return ret;
    if (!root->left && !root->right) ret.push_back(to_string(root->val));

    vector<string> left = binaryTreePaths(root->left);
    vector<string> right = binaryTreePaths(root->right);

    for (int i = 0; i < left.size(); i++) {
        ret.push_back(to_string(root->val) + "->" + left[i]);
    }
    for (int i = 0; i < right.size(); i++) {
        ret.push_back(to_string(root->val) + "->" + right[i]);
    }
    return ret;
}

/**
 1
 /   \
 2    3
 \
 4
 */

int main () {

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);

    node1->left = node2;
    node1->right = node3;
    node2->right = node4;

    binaryTreePaths(node1);
    return 0;
}
