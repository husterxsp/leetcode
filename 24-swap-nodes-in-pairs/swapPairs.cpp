#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode *prev, *cur, *tmp, *pointer;
    pointer = new ListNode(0);
    prev = pointer;
    cur = head;
    prev->next = cur;
    while (cur != NULL && cur->next != NULL) {
        tmp = cur->next;
        cur->next = cur->next->next;
        tmp->next = cur;
        prev->next = tmp;
        
        cur = cur->next;
        prev = prev->next->next;
    }
    return pointer->next;
}

int main(){
    ListNode *input;
    input = new ListNode(1);
    input->next = new ListNode(2);
    input->next->next = new ListNode(3);
    input->next->next->next = new ListNode(4);
    swapPairs(input);
    return 0;
}