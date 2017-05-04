#include <iostream>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    int sum = 0, carry = 0;

    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;

        sum = carry + n1 + n2;
        carry = sum / 10;

        p->next = new ListNode(sum % 10);
        p = p->next;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    if (carry) p->next = new ListNode(carry);
    return dummy->next;
}

int main() {
    ListNode* p = new ListNode(5);
    addTwoNumbers(p, p);
    return 0;
}
