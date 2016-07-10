#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode result = {2, NULL};
    struct ListNode *pointer = &result;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            pointer->next = l1;
            l1 = l1->next;
        } else {
            pointer->next = l2;
            l2 = l2->next;
        }
        pointer = pointer->next;
    }
    if (l1 != NULL) {
        pointer->next = l1;
    } else {
        pointer->next = l2;
    }
    return result.next;
}

int main(){
    struct ListNode l1 = {1, NULL}, l2 = {2, NULL}, *result;
    result = mergeTwoLists(&l1, &l2);
    cout<<result->next<<endl;
    return 0;
}