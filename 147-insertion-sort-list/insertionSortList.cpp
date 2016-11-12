#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    TreeNode *p = head;
    while (p) {

    }
    return head;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *node = new ListNode(2);
    node->right = new ListNode(3);
    head->left = node;
    insertionSortList(head);
    return 0;
}
