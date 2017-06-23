/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int search(TreeNode* root, unordered_map<int, int> &myMap) {
        if (!root) return 0;

        int left = search(root->left, myMap);
        int right = search(root->right, myMap);

        int ret = root->val + left + right;
        myMap[ret]++;
        return ret;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> myMap;
        search(root, myMap);

        vector<int> ret;
        int curMax = INT_MIN;
        for (auto itor : myMap) {
            if (itor.second > curMax) {
                ret.clear();
                curMax = itor.second;
            }
            if (itor.second >= curMax) ret.push_back(itor.first);
        }
        return ret;
    }
};
