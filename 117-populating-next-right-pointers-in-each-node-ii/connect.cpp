#include <iostream>
#include <vector>
#include <queue>
#include <Map>
#include <cmath>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if(!root) return;
    queue<TreeLinkNode*> q1;
    queue<TreeLinkNode*> q2;

    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
        if(!q1.empty()){
            while (!q1.empty()) {
                TreeLinkNode* node = q1.front();
                q1.pop();
                if(!q1.empty()) {
                    node->next = q1.front();
                }
                if(node->left) q2.push(node->left);
                if(node->right) q2.push(node->right);
            }
        } else {
            while (!q2.empty()) {
                TreeLinkNode* node = q2.front();
                q2.pop();
                if(!q2.empty()){
                    node->next = q2.front();
                }
                if(node->left) q1.push(node->left);
                if(node->right) q1.push(node->right);
            }
        }
    }
    return;
}

int main(){
    TreeLinkNode * root = new TreeLinkNode(1);
    TreeLinkNode * node1 = new TreeLinkNode(2);
    TreeLinkNode * node2 = new TreeLinkNode(3);

    root->left = node1;
    root->right = node2;
    connect(root);
    return 0;
}
