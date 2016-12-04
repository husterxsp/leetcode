#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 参看上一题
// .....Time Limit Exceeded...input: 19.
// 另外，这题如果数比较大，超出int怎么办？
// vector<TreeNode*> generate(int head, int tail) {
//     vector<TreeNode*> ret;
//     if (head == tail) {
//         ret.push_back(new TreeNode(head));
//         return ret;
//     }
//     if (head > tail) {
//         ret.push_back(NULL);
//         return ret;
//     }
//     for(int i = head;i <= tail; i++) {
//         vector<TreeNode*> left = generate(head, i - 1);
//         vector<TreeNode*> right = generate(i + 1, tail);
//         for (int l = 0; l < left.size(); l++) {
//             for (int r = 0; r < right.size(); r++) {
//                 TreeNode* root = new TreeNode(i);
//                 root->left = left[l];
//                 root->right = right[r];
//                 ret.push_back(root);
//             }
//         }
//     }
//     return ret;
// }
// int numTrees(int n) {
//     vector<TreeNode*> ret;
//     if (n == 0) return 0;
//     return generate(1, n).size();
// }

// 依旧超时。。input: 19
// int generate(int head, int tail) {
//     int ret = 0;
//     if (head >= tail) {
//         return 1;
//     }
//     for(int i = head;i <= tail; i++) {
//         int left = generate(head, i - 1);
//         int right = generate(i + 1, tail);
//         ret += left * right;
//     }
//     return ret;
// }
//
// int numTrees(int n) {
//     vector<TreeNode*> ret;
//     if (n == 0) return 0;
//     return generate(1, n);
// }

// 一维动态规划，因为题目只要求计算数目，所以跟结构没关系，所以比如[1, 2, 3]和[4, 5, 6]的可能的结构数都是5
// n==20就溢出了。。测试用例就1...19
int numTrees(int n) {
    vector<int> ret(n + 1, 0);
    if (n == 0) return 0;
    ret[0] = 1;
    ret[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            ret[i] += ret[j] * ret[i - j - 1];
        }
    }
    return ret[n];
}

int main() {
    cout << numTrees(10);
    return 0;
}
