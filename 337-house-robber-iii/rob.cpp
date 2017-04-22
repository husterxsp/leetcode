#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
 3
 / \
 2   3
 \   \
 3   1

 层序遍历？...卧槽。。。错了.不一定是隔一个，还可能是隔两个。
 4
 /
 1
 /
 2
 /
 3   比如这个就是其实 4 + 3 = 7 最大。。。

 */
// int rob(TreeNode* root) {
//     vector<TreeNode*> layer1;
//     vector<TreeNode*> layer2;
//     int sum1 = 0, sum2 = 0;
//
//     if (!root) return 0;
//     layer1.push_back(root);
//
//     while (layer1.size() || layer2.size()) {
//         if (layer1.size()) {
//             while (layer1.size()) {
//                 TreeNode* tmp = layer1.back();
//                 layer1.pop_back();
//
//                 sum1 += tmp->val;
//
//                 if (tmp->left) layer2.push_back(tmp->left);
//                 if (tmp->right) layer2.push_back(tmp->right);
//             }
//         }
//         else {
//             while (layer2.size()) {
//                 TreeNode* tmp = layer2.back();
//                 layer2.pop_back();
//
//                 sum2 += tmp->val;
//
//                 if (tmp->left) layer1.push_back(tmp->left);
//                 if (tmp->right) layer1.push_back(tmp->right);
//             }
//         }
//     }
//     return sum1 > sum2 ? sum1 : sum2;
// }

vector<int> dfs(TreeNode* root) {
    if (!root) return vector<int>(2, 0);

    vector<int> left = dfs(root->left);
    vector<int> right = dfs(root->right);

    vector<int> ret(2, 0);
    // ret[0] 不包含root
    ret[0] = max(left[0], left[1]) + max(right[0], right[1]);
    ret[1] = root->val + left[0] + right[0];

    return ret;
}
int rob(TreeNode* root) {
    vector<int> ret = dfs(root);
    return max(ret[0], ret[1]);
}

int main () {

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(3);

    node5->right = node4;
    node5->left = node2;
    node2->left = node3;
    node4->right = node1;
    cout << rob(node5) << endl;
    return 0;
}
