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

// 中序遍历非递归实现
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ret;
    vector<TreeNode*> stack;
    struct TreeNode* pointer = root;
    while (pointer || stack.size()) {
        if(pointer){
            if(pointer->left){
                stack.push_back(pointer);
                pointer = pointer->left;
            }else {
                ret.push_back(pointer->val);
                pointer = pointer->right;
            }
        } else {
            pointer = stack.back();
            stack.pop_back();
            ret.push_back(pointer->val);
            pointer = pointer->right;
        }
    }
    return ret;
}

int main()
{
    struct TreeNode* root = new TreeNode(2);
    struct TreeNode* node1 = new TreeNode(3);
    struct TreeNode* node2 = new TreeNode(1);
    
    root->left = node1;
    node1->left = node2;
    inorderTraversal(root);
    return 0;
}
