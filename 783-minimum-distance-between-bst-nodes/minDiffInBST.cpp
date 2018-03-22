struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历

class Solution {
public:
    vector<int> arr;
    void midTraverse(TreeNode* root) {
        if (!root) return;
        midTraverse(root->left);
        arr.push_back(root->val);
        midTraverse(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        midTraverse(root);

        int ret = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            ret = min(ret, arr[i] - arr[i - 1]);
        }
        return ret;
    }
};
