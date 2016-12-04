#include <iostream>
#include <vector>
#include <Map>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 考虑失误，如[10,5,15,null,null,6,20]的情况未考虑到。
// 需要记录上一节点的值以及进入的方向。
// 错解
//bool validBST(TreeNode* root, int rootVal, bool isLeft){
//    if(!root){
//        return true;
//    }
//    if(root->left){
//        if(root->left->val >= root->val){
//            return false;
//        }
//        if(!isLeft && root->left->val <= rootVal){
//            return false;
//        }
//    }
//    if(root->right){
//        if(root->right->val <= root->val){
//            return false;
//        }
//        if(isLeft && root->right->val >= rootVal){
//            return false;
//        }
//    }
//    return validBST(root->left, root->val, 1) && validBST(root->right, root->val, 0);
//}
//bool isValidBST(TreeNode* root) {
//    if(!root){
//        return true;
//    }
//    if(root->left && root->left->val >= root->val){
//        return false;
//    }
//    if(root->right && root->right->val <= root->val){
//        return false;
//    }
//    return validBST(root->left, root->val, 1) && validBST(root->right, root->val, 0);
//}

// wrong
// bool validBST(TreeNode* root, int min, int max){
//     if(!root || (!root->left&&!root->right)) return true;
//     if(root->val <= min || root->val >= max) return false;
//     return validBST(root->left, min, root->val) && validBST(root->right, root->val, max);
// }
// bool isValidBST(TreeNode* root){
//     return validBST(root, INT_MIN, INT_MAX);
// }

// 思路：先中序遍历，再for循环, AC
// 参看 T145 后序遍历
bool isValidBST(TreeNode* root) {
    vector<int> arr;
    stack<TreeNode*> s;
    TreeNode* lastNode = NULL;
    TreeNode* p = root;
    if (!root) {
        return true;
    }
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        arr.push_back(p->val);
        if (!p->right) {
            p = NULL;
        }
        else {
            p = p->right;
        }
    }
    for (int i = 0; i < arr.size() - 1; i++) {
        if (arr[i] >= arr[i + 1]) return false;
    }
    return true;
}

int main()
{
    struct TreeNode* root = new TreeNode(2);
    struct TreeNode* node1 = new TreeNode(1);
    struct TreeNode* node2 = new TreeNode(3);

    root->left = node1;
    root->right = node2;
    cout << isValidBST(NULL);
    return 0;
}
