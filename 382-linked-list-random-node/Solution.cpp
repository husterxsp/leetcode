#include <iostream>
#include <vector>
using namespace std;

/*
 蓄水池抽样（Reservoir Sampling）原理
 http://www.cnblogs.com/HappyAngel/archive/2011/02/07/1949762.html
 这个博客还有好多疑问，比如如何从未知或者很大样本空间随机地取k个数？
 因为是概率问题，会不会最后取不到k个数，然后因为N很大，那循环什么时候结束，一直到N?

 wiki, https://zh.wikipedia.org/wiki/%E6%B0%B4%E5%A1%98%E6%8A%BD%E6%A8%A3

從S中抽取首k項放入「水塘」中
對於每一個S[j]項（j ≥ k）：
   隨機產生一個範圍從0到j的整數r
   若 r < k 則把水塘中的第r項換成S[j]項

这个地方是不是写错了？ 把水塘的第r项？r大于k怎么办？ 感觉应该是将第rand(k)项替换
注意不能是 r % k, 这种情况需要保证j是k的倍数，概率才一样?
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
private:
    ListNode* root;
public:
    /** @param head The linked list's head.
     Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        root = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int i = 1;
        int ret = root->val;

        ListNode* p = root->next;
        while (p) {
            int choice = rand() % ++i + 1;
            if (choice == i) ret = p->val;
            p = p->next;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution obj = Solution(head);
    int i = 0;
    while (i++ < 1000) {
        cout << obj.getRandom() << endl;
    }
    return 0;
}
