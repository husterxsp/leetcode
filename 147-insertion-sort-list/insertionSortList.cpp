#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

/**
    参见：http://www.cnblogs.com/springfor/p/3862468.html
    Insertion Sort就是把一个一个元素往已排好序的list中插入的过程。
    初始时，sorted list是空，把一个元素插入sorted list中。然后，在每一次插入过程中，都是找到最合适位置进行插入。
    因为是链表的插入操作，需要维护pre，cur和next3个指针。
    pre始终指向sorted list的fakehead，cur指向当前需要被插入的元素，next指向下一个需要被插入的元素。
    当sortedlist为空以及pre.next所指向的元素比cur指向的元素值要大时，需要把cur元素插入到pre.next所指向元素之前。
    否则，pre指针后移。最后返回fakehead的next即可。
*/
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    ListNode* cur = head;
    ListNode* next;
    ListNode* prev;
    while (cur) {
        next = cur->next;
        prev = dummy;
        while (prev->next && prev->next->val < cur->val) {
            prev = prev->next;
        }
        cur->next = prev->next;
        prev->next = cur;
        cur = next;
    }
    return dummy->next;
}

int main(){
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(1);
    ListNode *node3 = new ListNode(4);
    ListNode *node4 = new ListNode(6);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    insertionSortList(node1);
    return 0;
}
