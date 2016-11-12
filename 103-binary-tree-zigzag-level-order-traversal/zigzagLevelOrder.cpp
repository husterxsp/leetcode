#include <iostream>
#include <vector>
#include <queue>
#include <Map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ret;
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    bool fromLeft = true;
    
    if(!root) return ret;
    q1.push(root);
    while (!q1.empty() || !q2.empty()) {
        vector<int> level;
        if(!q1.empty()){
            while (!q1.empty()) {
                level.push_back(q1.front()->val);
                if(q1.front()->left) q2.push(q1.front()->left);
                if(q1.front()->right) q2.push(q1.front()->right);
                q1.pop();
            }
        } else if(!q2.empty()){
            while (!q2.empty()) {
                level.push_back(q2.front()->val);
                if(q2.front()->left) q1.push(q2.front()->left);
                if(q2.front()->right) q1.push(q2.front()->right);
                q2.pop();
            }
        }
        if(!fromLeft){
            reverse(level.begin(), level.end());
        }
        ret.push_back(level);
        fromLeft = !fromLeft;
    }
    return ret;
}
int main(){
    TreeNode* root = new TreeNode(3);
    levelOrder(root);
}
