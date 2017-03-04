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

class BSTIterator {
public:
    queue<TreeNode *> list;
    BSTIterator(TreeNode *root) {
        stack<TreeNode *> myStack;
        while (root) {
            while (root->left) {
                myStack.push(root);
                root = root->left;
            }
            list.push(root);
            root = root->right;
            if (!root && !myStack.empty()) {
                root = myStack.top();
                root->left = NULL;
                myStack.pop();
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !list.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ret = list.front();
        list.pop();
        return ret->val;
    }
};
/**
    2
   / \
  1   4
     / \
    3   5
*/
int main () {

    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);

    node2->left = node1;
    node2->right = node4;
    node4->left = node3;
    node4->right = node5;

    BSTIterator i = BSTIterator(node2);
    while (i.hasNext()) {
        cout << i.next() << endl;
    }
    return 0;
}
