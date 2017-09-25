//  vector<vector<string>> ret;
//  vector<vector<TreeNode*>> tmpRet;
//  if (!root) return ret;
//
//  vector<TreeNode*> vec{root};
//  while (1) {
//      vector<TreeNode*> tmpVec;
//      int size = 0;
//
//      for (auto node : vec) {
//          if (node) {
//              tmpVec.insert(tmpVec.end(), {node->left, node->right});
//              size++;
//          }
//          else {
//              tmpVec.insert(tmpVec.end(), {NULL});
//
// }
//      }
//      if (size == 0) break;
//
//      tmpRet.push_back(vec);
//      vec = tmpVec;
//  }

// A不动
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//
// class Solution {
// public:
//     void insertEmpty(vector<string>& v, int s) {
//         v.insert(v.begin(), s / 2, "");
//         v.insert(v.end(), s / 2, "");
//     }
//     vector<string> help(TreeNode* root, int height, vector<vector<string>>& ret) {
//         vector<string> curRet;
//         if (!root) return curRet;
//         if (!root->left && !root->right) {
//             curRet.push_back(to_string(root->val));
//             return curRet;
//         }
//
//         vector<string> l = help(root->left, height + 1);
//         vector<string> r = help(root->right, height + 1);
//
//         if (l.size() < r.size()) insertEmpty(l, r.size() - l.size());
//         else if (l.size() > r.size()) insertEmpty(r, l.size() - r.size());
//
//         ret[height + 1].insert(ret[height + 1].end(), l.begin(), l.end());
//         ret[height + 1].insert(ret[height + 1].end(), "");
//         ret[height + 1].insert(ret[height + 1].end(), r.begin(), r.end());
//
//         curRet.push_back(to_string(root->val));
//         insertEmpty(curRet, l.size() * 2);
//
//         return curRet;
//     }
//     vector<vector<string>> printTree(TreeNode* root) {
//         vector<vector<string>> ret;
//
//         help(root, 0, ret);
//
//         return ret;
//     }
// };


// 参考：http://www.cnblogs.com/grandyang/p/7489097.html
class Solution {
public:
    int getHeight(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
    void helper(TreeNode* root, int i, int j, int curH, int h, vector<vector<string>>& ret) {
        if (!root || curH == h) return;
        ret[curH][(i + j) / 2] = to_string(root->val);
        helper(root->left, i, (i + j) / 2 - 1, curH + 1, h, ret);
        helper(root->right, (i + j) / 2 + 1, j, curH + 1, h, ret);
    }
    // 这个宽度和高度的关系怎么看出来的？
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root), w = pow(2, h) - 1;
        vector<vector<string>> ret(h, vector<string>(w, ""));

        helper(root, 0, w - 1, 0, h, ret);
        return ret;
    }
};
