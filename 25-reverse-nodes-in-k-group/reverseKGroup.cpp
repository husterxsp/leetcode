// #include <iostream>
// #include <stdio.h>
// #include <vector>
// using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
// };

// ListNode* reverseKGroup(ListNode* head, int k) {
//     if(head == NULL || head->next == NULL){
//         return head;
//     }
//     ListNode *node1, *node2, *prevNode1, *prevNode2, *nextNode1, *nextNode2, *pointer;
//     pointer = new ListNode(0);
//     pointer->next = head;
//     prevNode1 = prevNode2 = pointer;
//     node1 = node2 = pointer->next;
//     nextNode1 = nextNode2 = pointer->next->next;
    
//     while (node1 != NULL) {
//         int i = k;
//         while(i-- > 1){
//             node2 = node2->next;
//             prevNode2 = prevNode2->next;
//             nextNode2 = nextNode2->next;
//             if(node2 == NULL){
//                 return pointer->next;
//             }
//         }
//         prevNode1->next = node2;
//         node2->next = nextNode1;
//         prevNode2->next = node1;
//         node1->next = nextNode2;
        
//     }
//     return pointer->next;
// }

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
// 
//