#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
// 各种操作时间复杂度都是On
using namespace std;
struct LRUNode {
    int key;
    int value;
    LRUNode *next;
    LRUNode(int x, int y) : key(x), value(y), next(NULL) {}
};
class LRUCache {
private:
    int capacity = 0;
    int linkLen = 0;
    LRUNode *head = NULL;
public:

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        LRUNode *prev = this->head;
        LRUNode *cur = this->head;

        if (!cur) return -1;
        if (cur->key == key) return cur->value;

        cur = cur->next;

        while (cur) {
            if (cur->key == key) {
                prev->next = cur->next;
                cur->next = this->head;
                this->head = cur;
                return cur->value;
            }
            prev = prev->next;
            cur = cur->next;
        }
        return -1;
    }

    void put(int key, int value) {
        LRUNode *prev = this->head;
        LRUNode *cur = this->head;

        // 更新
        if (cur) {
            if (cur->key == key) {
                cur->value = value;

                return;
            }
            cur = cur->next;
            while (cur) {
                if (cur->key == key) {
                    cur->value = value;
                    prev->next = cur->next;
                    cur->next = this->head;
                    this->head = cur;
                    return;
                }
                cur = cur->next;
                prev = prev->next;
            }
        }

        // 插入
        LRUNode * tmp = new LRUNode(key, value);
        tmp->next = this->head;
        this->head = tmp;
        this->linkLen++;

        if (this->linkLen > capacity) {
            LRUNode * tail = this->head;
            int i = 1;
            while (i < capacity) {
                tail = tail->next;
                i++;
            }
            tail->next = NULL;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main(){
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;       // returns 1
    cache.put(3, 3);                    // evicts key 2
    cout << cache.get(2) << endl;       // returns -1 (not found)
    cache.put(4, 4);                    // evicts key 1
    cout << cache.get(1) << endl;       // returns -1 (not found)
    cout << cache.get(3) << endl;       // returns 3
    cout << cache.get(4) << endl;       // returns 4
    return 0;
}
