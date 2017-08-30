struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 /*
    思路：将树转换为字符串再比较是否相等，注意字符串拼接的时候需要用括号将节点分隔开。
    避免以下这种情况
      12    2
     /     /
    3     31
 */
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
     string help(TreeNode* root, unordered_map<string, vector<TreeNode*>>& myMap) {
         if (!root) return "";
         string str = to_string(root->val) + "(" + help(root->left, myMap) + "," + help(root->right, myMap) + ")";
         myMap[str].push_back(root);
         return str;
     }
     vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
         vector<TreeNode*> ret;
         unordered_map<string, vector<TreeNode*>> myMap;

         help(root, myMap);

         for (auto v : myMap) {
             if (v.second.size() > 1) ret.push_back(v.second[0]);
         }

         return ret;
     }
 };
