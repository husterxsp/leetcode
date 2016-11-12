#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//因为此题可循环移动，必须先进行一次遍历得到长度n。
//之后可使用一个指针，移动 n-k%n 次即可。
//另外如果没有循环的情况下，可以不用先知道n(需两次遍历)，用两个指针，对链表进行一次遍历，即可找到倒数第k个数字。
ListNode* rotateRight(ListNode* head, int k) {
    if(head == NULL || head->next == NULL || k==0){
        return head;
    }
    ListNode *fake = new ListNode(0);
    fake->next = head;

    int length = 0;
    while (head != NULL) {
        head = head->next;
        length++;
    }
    k = k % length;
    head = fake;
    for(int i=0;i<k;i++){
        head = head->next;
    }
    ListNode *tail = fake;
    while (head->next != NULL) {
        head = head->next;
        tail = tail->next;
    }
    head->next = fake->next;
    fake->next = tail->next;
    tail->next = NULL;
    return fake->next;
}

int main()
{
    struct ListNode* root = new ListNode(1);
    struct ListNode* node1 = new ListNode(2);
    struct ListNode* node2 = new ListNode(3);
    struct ListNode* node3 = new ListNode(4);
    struct ListNode* node4 = new ListNode(5);
    
    root->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    rotateRight(root, 5);
    return 0;
}
