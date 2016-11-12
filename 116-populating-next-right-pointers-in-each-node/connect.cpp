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
    queue<TreeLinkNode*> myQueue;
    int level = 0;
    myQueue.push(root);
    while (!myQueue.empty()) {
        int num = pow(2, level);
        for(int i=0;i<num;i++){
            TreeLinkNode* node = myQueue.front();
            myQueue.pop();
            if(i == num-1){
                node->next = NULL;
            } else {
                node->next = myQueue.front();
            }
            if(node->left && node->right){
                myQueue.push(node->left);
                myQueue.push(node->right);
            }
        }
        level++;
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
