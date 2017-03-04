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
/*
 O(nlogn) 时间复杂度，分治算法。
 */

ListNode* merge(ListNode* p1, ListNode* p2) {
    ListNode* dummy = new ListNode(0);
    ListNode* p = dummy;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            p->next = p1;
            p1 = p1->next;
        }
        else {
            p->next = p2;
            p2 = p2->next;
        }
        p = p->next;
    }
    if (p1) {
        p->next = p1;
    }
    else {
        p->next = p2;
    }
    return dummy->next;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = slow->next;
    slow->next = NULL;
    ListNode* p1 = sortList(head);
    ListNode* p2 = sortList(fast);

    return merge(p1, p2);
}

int main() {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    ListNode* ret = sortList(node1);
    return 0;
}
