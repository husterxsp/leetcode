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
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// 如何记录节点是否已经被访问过是一个问题
// map: node -> cloneNode
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return NULL;

    UndirectedGraphNode* p1 = node;
    UndirectedGraphNode* p2 = new UndirectedGraphNode(p1->label);

    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> myMap;
    queue<UndirectedGraphNode*> myQueue;

    myQueue.push(p1);
    myMap[node] = p2;

    while (!myQueue.empty()) {
        p1 = myQueue.front();
        p2 = myMap[p1];
        myQueue.pop();
        for (int i = 0; i < p1->neighbors.size(); i++) {
            UndirectedGraphNode* neighbor = p1->neighbors[i];
            if (!myMap.count(neighbor)) {
                UndirectedGraphNode* tmp = new UndirectedGraphNode(neighbor->label);
                myMap[neighbor] = tmp;
                myQueue.push(neighbor);
            }
            p2->neighbors.push_back(myMap[neighbor]);
        }
    }
    UndirectedGraphNode* ret = myMap[node];
    return ret;
}
/**
*       0
*      /
*      1 -- 2 --/
*           |  /
*           |/
**/


int main(){
    UndirectedGraphNode* node0 = new UndirectedGraphNode(0);
    UndirectedGraphNode* node1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* node2 = new UndirectedGraphNode(2);
    node0->neighbors.push_back(node1);
    node1->neighbors.push_back(node2);
    node2->neighbors.push_back(node2);

    cloneGraph(node0);
    return 0;
}
