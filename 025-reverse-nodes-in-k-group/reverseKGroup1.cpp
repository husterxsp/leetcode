// #include <iostream>
// #include <stdio.h>
// #include <vector>
// using namespace std;
//
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };
//
    // 理解错题意。。。。4，2，3，1
// ListNode* reverseKGroup(ListNode* head, int k) {
//     if(k <= 1) return head;
//
//     ListNode *fake = new ListNode(0);
//     ListNode *p1, *p2, *tmp1, *tmp2;
//     fake->next = head;
//     p1 = p2 = fake;
//     p1 = skip(p1, k-1);
//     while (p1 && p1->next) {
//         tmp1 = p1->next;
//         p1->next = skip(p1, 2);
//         tmp1->next = NULL;
//
//         tmp2 = p2->next;
//         p2->next = skip(p2, 2);
//         tmp2->next = NULL;
//
//         tmp1->next = p2->next;
//         p2->next = tmp1;
//
//         tmp2->next = p1->next;
//         p1->next = tmp2;
//     }
//     return pointer->next;
// }
//
// ListNode* skip(ListNode* node, int steps){
//     while (steps-- && node) {
//         node = node->next;
//     }
//     return node;
// }
//
// int main(){
//     ListNode *input, *pointer;
//     input = new ListNode(1);
//     pointer = input;
//     int k = 1;
//     while(k++ < 10){
//         pointer->next = new ListNode(k);
//         pointer = pointer->next;
//     }
//     reverseKGroup(input, 4);
//     return 0;
// }
