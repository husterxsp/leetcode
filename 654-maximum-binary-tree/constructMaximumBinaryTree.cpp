struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* ret = NULL;
        if (nums.size() == 0) return ret;

        auto maximum = max_element(nums.begin(), nums.end());
        int dis = distance(nums.begin(), maximum);
        ret = new TreeNode(*maximum);

        vector<int> left(nums.begin(), nums.begin() + dis);
        vector<int> right(nums.begin() + dis + 1, nums.end());

        ret->left = constructMaximumBinaryTree(left);
        ret->right = constructMaximumBinaryTree(right);
        return ret;
    }
};
