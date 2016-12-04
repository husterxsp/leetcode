#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 这样形成的环是不是一定在链表的末尾？
// 思路：双指针
// ....数学题？卧槽。。。
// runtime error, no cycle
ListNode* detectCycle(ListNode *head) {
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (p1 && p2) {
        p1 = p1->next;
        p2 = p2->next;
        p2 = p2 ? p2->next : p2;

        if(!p1 || !p2) return NULL;
        if(p1 == p2) break;
    }
    p1 = head;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    p->next = new ListNode(2);
    p->next->next = new ListNode(3);
    p = p->next->next;
    detectCycle(head);
    return 0;
}
