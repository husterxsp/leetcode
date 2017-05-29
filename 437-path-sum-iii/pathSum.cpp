#include <iostream>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
    MLE,内存超出限制。。。
*/
int search(TreeNode* root, int sum, unordered_multiset<int> setArgs) {
    if (!root) return 0;
    int ret = 0;
    if (root->val == sum) ret++;
    ret += setArgs.count(sum - root->val);

    unordered_multiset<int> mySet = {root->val};
    for (auto i : setArgs) mySet.insert(i + root->val);

    return ret + search(root->left, sum, mySet) + search(root->right, sum, mySet);
}
int pathSum(TreeNode* root, int sum) {
    return search(root, sum, {});
}

/**
    只保留一个整数
    思路，sum包不包括root分为两种情况
    但是。。以下这种写法还是有问题，会比正确解多。画个递归示意图可以看出来
    对于1-2-3，路径1-2-3和2-3，最后一步如果都不算pre,结果就会有两个。
*/
int search(TreeNode* root, int sum, int pre) {
    if (!root) return 0;
    int cur = prev + root->val;
    return (cur == sum)
        + search(root->left, sum, 0) + search(root->right, sum, 0)
        + search(root->left, sum, cur) + search(root->right, sum, cur);
}
int pathSum(TreeNode* root, int sum) {
    return search(root, sum, 0);
}

/**
    正解，这个解法的每个路径的和都会从开始加到最后。
*/
int search(TreeNode* root, int sum, int pre) {
    if (!root) return 0;
    int cur = pre + root->val;
    return (cur == sum) + search(root->left, sum, cur) + search(root->right, sum, cur);
}
int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    int rootPath = search(root, sum, 0);
    return rootPath + pathSum(root->left, sum) + pathSum(root->right, sum);
}
/**
      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
*/
int main() {
    TreeNode* node1 = new TreeNode(10);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(-3);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(11);
    TreeNode* node7 = new TreeNode(3);
    TreeNode* node8 = new TreeNode(-2);
    TreeNode* node9 = new TreeNode(1);
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->right = node6;
    node5->right = node9;
    cout << pathSum(node1, 8) << endl;
    return 0;

}
