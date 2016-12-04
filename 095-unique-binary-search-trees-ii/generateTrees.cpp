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
// 思路：实际是求 1...n 的中序遍历有多少种
// 直接递归解坑定超时，需要动态规划。计算过程中保存已计算过
// wrong answer: 0 expected: [], output: [[]], 是那个push_back(NULL)的锅
// 觉得好多冗余计算可以优化。。。居然能AC。。下次再看想想有啥优化
// vector<vector<TreeNode*>> saveLeft;
vector<TreeNode*> generate(int head, int tail) {
    vector<TreeNode*> ret;
    if (head == tail) {
        ret.push_back(new TreeNode(head));
        return ret;
    }
    if (head > tail) {
        ret.push_back(NULL);
        return ret;
    }
    for(int i = head;i <= tail; i++) {
        vector<TreeNode*> left = generate(head, i - 1);
        vector<TreeNode*> right = generate(i + 1, tail);
        // if (head == 1) {
        //     saveLeft.push_back(ret);
        // }
        for (int l = 0; l < left.size(); l++) {
            for (int r = 0; r < right.size(); r++) {
                TreeNode* root = new TreeNode(i);
                root->left = left[l];
                root->right = right[r];
                ret.push_back(root);
            }
        }
    }
    return ret;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode*> ret;
    if (n == 0) return ret;
    return generate(1, n);
}

int main() {
    generateTrees(0);
    return 0;
}
