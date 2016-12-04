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
// 思路：先分别遍历得到两个链表的长度差，然后再同时遍历。
// 思路正确，但总是runtime error。什么👻，内存错误，读写越界
// 超时会报错time limit exceeded
// 确认问题：两个if的问题，改成 else if 就好了
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    ListNode *A = headA;
    ListNode *B = headB;
    int aLen = 0, bLen = 0;
    while (A != NULL) {
        aLen++;
        A = A->next;
    }
    while (B != NULL) {
        bLen++;
        B = B->next;
    }
    A = headA;
    B = headB;
    int diff = aLen - bLen;
    if (diff > 0) {
        // 注意此处，diff 减了三次，while循环执行了两次
        while (diff-- > 0) {
            A = A->next;
        }
    }
    else if (diff < 0) {
        while (diff++ < 0) {
            B = B->next;
        }
    }
    while (A != NULL) {
        if (A == B) return A;
        A = A->next;
        B = B->next;
    }
    return NULL;
}

int main () {
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(2);
    A->next = new ListNode(3);
    A->next->next = new ListNode(4);
    getIntersectionNode(B, A);
    return 0;
}
