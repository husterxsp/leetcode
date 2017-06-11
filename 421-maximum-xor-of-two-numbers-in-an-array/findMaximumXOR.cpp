#include <iostream>
#include <vector>
#include <Map>
#include <Set>
#include <unordered_set>

using namespace std;
/**
    解法1，超时TLE。。。
    思路：异或的两个数的其中一个的最高位坑定是1，然后一位一位地往下比较。
*/
// int findMaximumXOR(vector<int>& nums) {
//     set<int> numSet(nums.begin(), nums.end());
//     int maxBit = 31, tmpMax = *numSet.rbegin();
//     while (maxBit >= 0) {
//         if (tmpMax & (1 << maxBit)) break;
//         else maxBit--;
//     }
//     // 最高位是1
//     set<int> maxSet;
//     for (auto num : numSet) {
//         if ((num >> maxBit) & 1) {
//             maxSet.insert(num);
//         }
//     }
//
//     int ret = 0;
//     for (auto tmpMax : maxSet) {
//         int tmpMaxBit = maxBit;
//         set<int> set1 = numSet, set2;
//         while (tmpMaxBit >= 0) {
//             int val = (tmpMax >> tmpMaxBit) & 1;
//
//             for (auto num : set1) {
//                 if (((num >> tmpMaxBit) & 1) != val) {
//                     set2.insert(num);
//                 }
//             }
//             if (!set2.empty()) {
//                 if (set2.size() == 1) {
//                     ret = max(ret, *set2.begin() ^ tmpMax);
//                     break;
//                 }
//                 else {
//                     set1 = set2;
//                     set2.clear();
//                 };
//             }
//             tmpMaxBit--;
//         }
//     }
//
//     return ret;
// }

struct TrieNode {
    int pos;
    set<TrieNode*> zeroSet;
    set<TrieNode*> oneSet;
    TrieNode() {}
};
int findMaximumXOR(vector<int>& nums) {
    set<int> numSet(nums.begin(), nums.end());
    int maxBit = 31, tmpMax = *numSet.rbegin();
    while (maxBit >= 0) {
        if (tmpMax & (1 << maxBit)) break;
        else maxBit--;
    }

    TrieNode *root = new TrieNode();
}

int main () {
    vector<int> nums = {10,23,20,18,28};
    cout << findMaximumXOR(nums) << endl;

    return 0;
}
