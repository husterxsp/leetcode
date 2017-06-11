#include <iostream>
#include <vector>
#include <Map>
#include <Set>
#include <unordered_set>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/**
    解法1.
*/
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string ret = to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        return ret;
    }

    vector<int> desHelp(string data) {
        vector<int> ret;
        int n = data.length(), pos = 0;

        while (pos < n) {
            string numStr = "";
            while (pos < n && data[pos] != ',') {
                numStr += data[pos];
                pos++;
            }
            ret.push_back(stoi(numStr));
            pos++;
        }
        return ret;
    }

    TreeNode* desVec(vector<int> data) {
        int n = data.size();
        if (!n) return NULL;
        TreeNode* ret = new TreeNode(data[0]);

        int pos = 1;
        while (pos < n && data[pos] < data[0]) pos++;

        vector<int> leftVec(data.begin() + 1, data.begin() + pos);
        vector<int> rightVec(data.begin() + pos, data.end());

        ret->left = desVec(leftVec);
        ret->right = desVec(rightVec);

        return ret;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> dataVec = desHelp(data);
        return desVec(dataVec);
    }
};

/**
    解法2. 使用istringstream和ostringstream处理
*/

/**
      4
    /   \
   2     5
  / \     \
 1   3     6
 */
int main () {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);

    node4->left = node2;
    node4->right = node5;

    node2->left = node1;
    node2->right = node3;

    node5->right = node6;

    Codec codec;
    codec.deserialize(codec.serialize(node4));
    return 0;
}
