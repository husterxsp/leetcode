#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int length = 1;
    struct ListNode *pointer = head;
    while (pointer->next != NULL) {
        pointer = pointer->next;
        length++;
    }
    if (length == n) {
        return head->next;
    }
    pointer = head;
    int index = length - n;
    while (index-- > 1) {
        pointer = pointer->next;
    }
    pointer->next = pointer->next->next;
    return head;
}

int main(){
    struct ListNode node2 = {2, NULL};
    struct ListNode node1 = {1, &node2};
    struct ListNode *tmp = removeNthFromEnd(&node1, 1);
    cout<< tmp->val<<endl;
    return 0;
}