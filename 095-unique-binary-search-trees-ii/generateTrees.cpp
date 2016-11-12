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
vector<TreeNode*> ret;
void generate(TreeNode*root, int head, int tail, int n) {
    if(head > tail || tail < 1 || head > n ) {
        return NULL;
    }
    for(int i=1;i<=n;i++) {
        TreeNode* root = new TreeNode(i);
        root->left = generate(root, 0, i-1, n);
        root->right = generate(root, i+1, n, n);
        ret.push_back(root);
    }
}

vector<TreeNode*> generateTrees(int n) {
    
    return ret;
}

int main() {
    generateTrees(3);
    return 0;
}
