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
// 思路：高度平衡的搜索二叉树，数组已排序，直接从中间切分。
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return NULL;
    if (n == 1) return new TreeNode(nums[0]);
    int mid = n / 2;

    TreeNode * root = new TreeNode(nums[mid]);
    vector<int> leftArr(nums.begin(), nums.begin() + mid);
    vector<int> rightArr(nums.begin() + mid + 1, nums.end());
    root->left = sortedArrayToBST(leftArr);
    root->right = sortedArrayToBST(rightArr);
    return root;
}

int main(){
    vector<int> arr = {1,2,3};
    sortedArrayToBST(arr);
    return 0;
}
