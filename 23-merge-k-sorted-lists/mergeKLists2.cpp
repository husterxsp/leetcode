#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *result = new ListNode(0);
    ListNode *pointer = result;
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
    return result->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
    int n = lists.size();
    if(n == 0){
        return NULL;
    }
    while (n > 1) {
        int k = (n + 1) / 2;
        for (int i = 0; i < n / 2; i++){
            lists[i] = mergeTwoLists(lists[i], lists[i + k]);
        }
        n = k;
    }
    return lists[0];
}

int main(){
    ListNode *input;
    input = new ListNode(1);
    input->next = new ListNode(3);
    vector<ListNode *> lists;
    lists.push_back(input);
    input = new ListNode(2);
    lists.push_back(input);
    cout << mergeKLists(lists)->val;
    return 0;
}