#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *from, *to, *p1, *p2, *dummy;
    int step = 1;
    if (!head || !head->next || m == n) return head;

    dummy = new ListNode(0);
    dummy->next = head;
    p1 = dummy;
    while (step < m) {
        p1 = p1->next;
        step++;
    }
    from = to = p2 = p1->next;
    p1->next = NULL;
    p2 = p2->next;
    while (step < n) {
        ListNode *tmp = to;
        to = p2;
        p2 = p2->next;
        from->next = NULL;
        to->next = tmp;
        step++;
    }
    p1->next = to;
    from->next = p2;
    return dummy->next;
}

int main () {
    ListNode* head = new ListNode(1);
    ListNode* p = head;
    int i = 1;
    while (i++ < 5) {
        p->next = new ListNode(i);
        p = p->next;
    }
    reverseBetween(head, 3, 4);
    return 0;
}
