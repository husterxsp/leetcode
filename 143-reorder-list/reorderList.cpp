#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* findMid(ListNode* head) {
    ListNode* p1 = head;
    ListNode* p2 = head;
    while (p2 && p2->next) {
        p1 = p1->next;
        p2 = p2->next;
        if (p2) {
            p2 = p2->next;
        }
    }
    return p1;
}
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* prev = head;
    ListNode* next = head->next;
    head->next = NULL;
    while (next) {
        prev = next;
        next = next->next;
        prev->next = head;
        head = prev;
    }
    return head;
}
void reorderList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return;
    ListNode* mid = findMid(head);
    ListNode* left = head;
    // 注意对next的处理
    ListNode* right = reverseList(mid->next);
    mid->next = NULL;
    ListNode* tmp;

    while (right) {
        tmp = right->next;
        right->next = left->next;
        left->next = right;
        left = left->next->next;
        right = tmp;
    }
}

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(7);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    reorderList(node1);
    return 0;
}
