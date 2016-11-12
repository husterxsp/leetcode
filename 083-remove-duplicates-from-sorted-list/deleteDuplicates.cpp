#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    struct ListNode *cur, *prev;
    if(head == NULL || head->next == NULL){
        return head;
    }
    prev = head;
    cur = head->next;
    while (cur != NULL) {
        if(cur->val == prev->val){
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
    return head;
}

int main()
{
    struct ListNode *node1 = new ListNode(1);
    struct ListNode *node2 = new ListNode(1);
    node2->next = node1;
    struct ListNode *ret = deleteDuplicates(node2);
    cout << ret->val;
    return 0;
}

