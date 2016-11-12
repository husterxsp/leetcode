TreeNode* getTree(vector<int> &pre, vector<int> &in, int i, int j, int len) {
    if(len <= 0){
        return NULL;
    }
    TreeNode* root = new TreeNode(pre[i]);
    int m = find(in.begin(), in.end(), pre[i]) -in.begin();
    root->left = getTree(pre, in, i+1, j, m-j);
    root->right = getTree(pre, in, i+(m-j)+1, m+1, len-1-(m-j));
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return getTree(preorder, inorder, 0, 0, preorder.size());
}
