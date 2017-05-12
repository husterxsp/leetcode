#include <iostream>
#include <vector>
#include <queue>

/**
    学习istringstream/ostringstream 用法。
    解法1，递归
    解法2，层序遍历
*/
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:
    void serialize(TreeNode* root, ostringstream &out) {
        if (root) {
            out << root->val << " ";
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;

        if (val == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);

        return deserialize(in);
    }
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> myQueue;
        if (root) myQueue.push(root);

        while (!myQueue.empty()) {
            TreeNode* tmp = myQueue.front();
            myQueue.pop();

            if (tmp) {
                out << tmp->val << " ";
                myQueue.push(tmp->left);
                myQueue.push(tmp->right);
            }
            else {
                out << "# ";
            }
        }
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }
        istringstream in(data);

        queue<TreeNode*> myQueue;

        string val;
        in >> val;

        TreeNode* ret = new TreeNode(stoi(val));
        TreeNode* cur = ret;

        myQueue.push(cur);
        while (!myQueue.empty()) {
            TreeNode* tmp = myQueue.front();
            myQueue.pop();

            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                tmp->left = cur;
                myQueue.push(cur);
            }
            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                tmp->right = cur;
                myQueue.push(cur);
            }
        }

        return ret;
    }
};

/**
  1
 / \
2   3
   / \
  4   5
*/
int main() {
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);

    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;

    Codec codec;
    codec.deserialize(codec.serialize(node1));
    return 0;
}
