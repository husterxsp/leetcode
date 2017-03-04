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
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
// 类似 133-clone-graph
// 但是这题没用queue, 直接用next指针，while循环终止为p1
RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return NULL;

    RandomListNode* p1 = head;
    RandomListNode* p2 = new RandomListNode(p1->label);

    unordered_map<RandomListNode*, RandomListNode*> myMap;
    myMap[head] = p2;

    while (p1) {
        if (p1->next) {
            if (!myMap.count(p1->next)) {
                myMap[p1->next] = new RandomListNode(p1->next->label);
            }
            p2->next = myMap[p1->next];
        }
        if (p1->random) {
            if (!myMap.count(p1->random)) {
                myMap[p1->random] = new RandomListNode(p1->random->label);
            }
            p2->random = myMap[p1->random];
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return myMap[head];
}

int main(){
    RandomListNode* node0 = new RandomListNode(0);
    RandomListNode* node1 = new RandomListNode(1);
    RandomListNode* node2 = new RandomListNode(2);
    RandomListNode* node3 = new RandomListNode(3);
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node1->random = node3;
    node2->random = node1;
    copyRandomList(node0);
    return 0;
}
