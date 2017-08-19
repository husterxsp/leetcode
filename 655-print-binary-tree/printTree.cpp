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
     vector<vector<string>> printTree(TreeNode* root) {
         vector<vector<string>> ret;
         vector<vector<TreeNode*>> tmpRet;
         if (!root) return ret;

         vector<TreeNode*> vec{root};
         while (1) {
             vector<TreeNode*> tmpVec;
             int size = 0;

             for (auto node : vec) {
                 if (node) {
                     tmpVec.insert(tmpVec.end(), {node->left, node->right});
                     size++;
                 }
                 else {
                     tmpVec.insert(tmpVec.end(), {NULL});
                 }
             }
             if (size == 0) break;

             tmpRet.push_back(vec);
             vec = tmpVec;
         }
         return ret;
     }
 };
