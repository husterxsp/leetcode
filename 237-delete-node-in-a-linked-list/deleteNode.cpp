#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    if (!node->next) return;

    node->val = ndoe->next->val;
    node->next = node->next->next;
}

/**
        6
      /  \
     2    8
    / \   / \
   0   4 7   9
*/
int main () {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    deleteNode(node1, node3);
    return 0;
}
