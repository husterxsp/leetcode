#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* getTree(vector<int> &in, vector<int> &post, int i, int j, int len) {
    if(len <= 0){
        return NULL;
    }
    TreeNode* root = new TreeNode(post[j]);
    int m = find(in.begin(), in.end(), post[j]) - in.begin();
//    root->left = getTree(in, post, i, m-1, m-i);
//    root->right = getTree(in, post, m+1, j-1, len-1-(m-i));
    root->left = getTree(in, post, i, j-1-(len-1-(m-i)), m-i);
    root->right = getTree(in, post, m+1, j-1, len-1-(m-i));
    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return getTree(inorder, postorder, 0, postorder.size()-1, inorder.size());
}
int main(){
    vector<int> in, post;
    in.push_back(1);
    in.push_back(3);
    in.push_back(2);
    post.push_back(3);
    post.push_back(2);
    post.push_back(1);
    buildTree(in, post);

}

