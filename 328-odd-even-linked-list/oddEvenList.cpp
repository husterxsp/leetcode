#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;

    ListNode* boundary, *last = head;
    while (last->next) {
        last = last->next;
    }
    boundary = last;

    ListNode* prev = head, *tmp = NULL;
    while (prev != boundary && tmp != boundary) {
        tmp = prev->next;
        prev->next = tmp->next;
        prev = prev->next;

        tmp->next = NULL;
        last->next = tmp;
        last = last->next;
    }
    return head;
}

int main () {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    oddEvenList(node1);
    return 0;
}
