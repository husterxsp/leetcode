/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /**
     解法1，虽然能AC，但是用了额外的存储空间
 */
class Solution {
public:
    void traverse(TreeNode* root, unordered_map<int, int>& myMap) {
        if (!root) return;
        myMap[root->val]++;
        traverse(root->left, myMap);
        traverse(root->right, myMap);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> myMap;
        traverse(root, myMap);

        int maxFrequence = INT_MIN;
        vector<int> ret;
        for (auto itor : myMap) {
            if (itor.second > maxFrequence) {
                ret.clear();
                ret.push_back(itor.first);
                maxFrequence = itor.second;
            }
            else if (itor.second == maxFrequence) {
                ret.push_back(itor.first);
            }
        }
        return ret;
    }
};
