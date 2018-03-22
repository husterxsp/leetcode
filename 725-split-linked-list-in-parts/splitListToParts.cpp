// easy
#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <bitset>
#include <cmath>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int n = 0;
    // 获取链表长度
    ListNode* p = root;
    while (p) {
        p = p->next;
        n++;
    }

    // 分段后每段的长度
    int averageSize = n / k;
    vector<int> lenArr(k, averageSize);
    for (int i = 0; i < n - averageSize * k; i++) lenArr[i]++;

    vector<ListNode*> ret(k);

    ListNode *p1 = root, *p2 = root;

    for (int i = 0; i < k; i++) {
        while (lenArr[i] > 1) {
            p2 = p2->next;
            lenArr[i]--;
        }
        // break 后的元素都为NULL
        if (!p1) break;
        ret[i] = p1;
        p1 = p2->next;
        p2->next = NULL;
        p2 = p1;
    }
    return ret;
}

int main() {
    ListNode *root = new ListNode(1), *p = root;
    for (int i = 2; i <= 2; i++) {
        p->next = new ListNode(i);
        p = p->next;
    }

    splitListToParts(root, 4);
    return 0;
}
