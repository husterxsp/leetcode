#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//超时
//int countNodes(TreeNode* root) {
//    if (!root) return 0;
//    queue<TreeNode*> myQueue;
//    myQueue.push(root);
//    int ret = 1;
//    while (!myQueue.empty()) {
//        TreeNode* node = myQueue.front();
//        myQueue.pop();
//        if (node && node->left) {
//            ret++;
//            myQueue.push(node->left);
//        }
//        if (node && node->right) {
//            ret++;
//            myQueue.push(node->right);
//        }
//    }
//    return ret;
//}
int countNodes(TreeNode* root) {
    int hLeft = 0, hRight = 0;
    TreeNode *pLeft = root, *pRight = root;
    while (pLeft) {
        hLeft++;
        pLeft = pLeft->left;
    }
    while (pRight) {
        hRight++;
        pRight = pRight->right;
    }
    if (hLeft == hRight) {
        return pow(2, hLeft) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main () {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);

    node1->left = node2;
    node1->right = node3;
    cout << countNodes(NULL) << endl;
    return 0;
}
