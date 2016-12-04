#include <iostream>
#include <vector>
#include <queue>
#include <Map>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 强行把list换成数组。。虽然也能AC，但好像不太好。。。直接操作List的话，那就是双指针，不同的移动速度了。
// 双指针似乎时间复杂度高了：http://bangbingsyb.blogspot.com/2014/11/leetcode-convert-sorted-list-to-binary.html
// http://articles.leetcode.com/convert-sorted-list-to-balanced-binary/
// 待用list重新AC
// 指针的引用理解的不太熟啊
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
TreeNode* sortedListToBST(ListNode* head) {
    vector<int> a;
    while (head != NULL) {
        a.push_back(head->val);
        head = head->next;
    }
    return sortedArrayToBST(a);
}

int main(){
    ListNode * list = new ListNode(1);
    ListNode * head = list;
    list->next = new ListNode(2);
    list = list->next;
    list->next = new ListNode(3);
    sortedListToBST(head);
    return 0;
}
