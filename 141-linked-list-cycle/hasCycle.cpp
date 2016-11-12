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

bool hasCycle(ListNode *head) {
    ListNode *p1 = head;
    ListNode *p2 = head;
    while (p1 && p2->next) {
        p1 = p1->next;
        p2 = p2->next->next;
        if(!p1 || !p2) return false;
        if(p1 == p2) return true;
    }
    return false;
}

int main(){
    ListNode *head = new ListNode(1);
    ListNode *node = new ListNode(2);
    head->next = node;
    cout << hasCycle(head);
    return 0;
}
