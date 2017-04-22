#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;

    // 找到链表中点
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 链表反转
    ListNode* prev = slow->next;
    ListNode* next = prev->next;
    prev->next = NULL;
    while (next) {
        ListNode* tmp = next->next;
        next->next = prev;
        prev = next;
        next = tmp;
    }

    slow->next = prev;

    fast = head;
    slow = slow->next;
    while (slow) {
        if (fast->val != slow->val) return false;
        fast = fast->next;
        slow = slow->next;
    }
    return true;
}

int main () {
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(0);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(0);
    ListNode* node6 = new ListNode(1);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    cout << isPalindrome(node1) << endl;
    return 0;
}
