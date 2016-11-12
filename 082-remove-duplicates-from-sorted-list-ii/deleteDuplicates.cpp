#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 此题边界条件较多，花了较多时间才AC
// 1.head可能一开始就重复，所以需要重新设置一个ret
// 2.head为NULL
// 3.第一个while终止时，curr为最后一个节点，此时应当考虑最后一个节点是否可用。故还需记录值tmp;
// 4.第二个while循环结束时考虑是哪个条件导致的结束
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* ret = new ListNode(0);
    ret->next = head;
    ListNode* prev = ret;
    ListNode* curr = head;

    if(head == NULL){
       return NULL;
    }
    int tmp = head->val;
    while (curr != NULL && curr->next != NULL) {
        if(curr->val == curr->next->val){
            tmp = curr->val;
            while(curr->next != NULL && curr->val == curr->next->val){
                curr = curr->next;
            }
            if(curr->next == NULL){
                prev->next = NULL;
                break;
            }
        } else {
            prev->next = curr;
            prev = prev->next;
        }
        curr = curr->next;
    }
    if(curr->val != tmp ){
        prev->next = curr;
    }
    return ret->next;
}

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    cout << deleteDuplicates(NULL);
    return 0;
}
