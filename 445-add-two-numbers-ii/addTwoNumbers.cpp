#include <iostream>
#include <string>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
    因为题目要求不能反转链表，所以只能先加高位，再加低位。
    转换为其他数据结构再从低位开始加的觉得也不符合题意。
*/
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = 0, len2 = 0;
    ListNode* p = l1;
    while (p) {
        len1++;
        p = p->next;
    }
    p = l2;
    while (p) {
        len2++;
        p = p->next;
    }

    string sum = "";
    int curLen = max(len1, len2);
    if (curLen == len1) {
        while (curLen > len2) {
            sum += to_string(l1->val);
            l1 = l1->next;
            curLen--;
        }
    }
    else {
        while (curLen > len1) {
            sum += to_string(l2->val);
            l2 = l2->next;
            curLen--;
        }
    }
    while (curLen > 0) {
        int tmpSum = l1->val + l2->val;
        int carry = tmpSum / 10;
        int remain = tmpSum % 10;
        if (carry) {
            for (int i = sum.size() - 1; i >= 0; i--) {
                if (sum[i] < '9') {
                    sum[i] += 1;
                    carry = 0;
                    break;
                }
                else {
                    sum[i] = '0';
                }
            }
            if (carry) sum = "1" + sum;
        }
        sum += to_string(remain);
        l1 = l1->next;
        l2 = l2->next;
        curLen--;
    }

    ListNode* ret = new ListNode(0);
    p = ret;
    for (int i = 0; i < sum.size(); i++) {
        p->next = new ListNode(sum[i] - '0');
        p = p->next;
    }
    return ret->next;
}
int main() {
    ListNode* node1 = new ListNode(7);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(3);
    ListNode* node5 = new ListNode(5);
    ListNode* node6 = new ListNode(6);
    ListNode* node7 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node5->next = node6;
    node6->next = node7;
    addTwoNumbers(node1, node5);
    return 0;
}
