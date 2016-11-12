#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// AC
// 思路：两个链表：一个小于，一个大于,最后连接，类似于归并排序
ListNode* partition(ListNode* head, int x) {
    ListNode* great = new ListNode(0);
    ListNode* less = new ListNode(0);
    ListNode* lessHead = less;
    ListNode* greatHead = great;
    while (head) {
        if(head->val < x){
            less->next = head;
            less = less->next;
        } else {
            great->next = head;
            great = great->next;
        }
        head = head->next;
        less->next = NULL;
        great->next = NULL;
    }
    less->next = greatHead->next;
    return lessHead->next;
}

int main()
{
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(1);
    node1->next = node2;
    partition(node1, 2);
    return 0;
}
