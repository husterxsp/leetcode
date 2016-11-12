#include <iostream>
#include <vector>
#include <queue>
#include <Map>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return NULL;
    int mid = n/2;
    TreeNode * root = new TreeNode(nums[mid]);
    vector<int> leftArr(nums.begin(), nums.begin()+mid);
    vector<int> rightArr(nums.begin()+mid+1, nums.end());
    root->left = sortedArrayToBST(leftArr);
    root->left = sortedArrayToBST(rightArr);
    return root;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    sortedArrayToBST(arr);
    return 0;
}
