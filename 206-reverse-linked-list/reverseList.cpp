#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* prev = NULL;
    ListNode* next = head->next;
    ListNode* nnext;
    while (head && next) {
        nnext = next->next;
        head->next = prev;
        next->next = head;
        prev = head;
        head = next;
        next = nnext;
    }
    return head;
}

int main () {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    reverseList(node1);
    return 0;
}
