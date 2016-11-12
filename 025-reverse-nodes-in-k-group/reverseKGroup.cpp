#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// AC
ListNode* skip(ListNode* node, int steps){
    while (steps-- && node) {
        node = node->next;
    }
    return node;
}
ListNode* reverse(ListNode* head, ListNode* tail){
    ListNode *p, *q, *r;
    p = head;
    q = head->next;
    head->next = NULL;
    while(p != tail){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    if(k <= 1) return head;
    ListNode *fake = new ListNode(0);
    ListNode *pHeadPrev = fake;
    ListNode *pTailNext = skip(head, k);
    fake->next = head;
    while (skip(pHeadPrev, k)) {
        pHeadPrev->next = reverse(head, skip(head, k-1));
        pHeadPrev = skip(pHeadPrev, k);
        pHeadPrev->next = pTailNext;
        pTailNext = skip(pTailNext, k);
        head = pHeadPrev->next;
    }
    return fake->next;
}

int main(){
    ListNode *input, *pointer;
    input = new ListNode(1);
    pointer = input;
    int k = 1;
    while(k++ < 10){
        pointer->next = new ListNode(k);
        pointer = pointer->next;
    }
    reverseKGroup(input, 4);
    return 0;
}
