#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

/*
 http://www.cnblogs.com/grandyang/p/4491665.html
 http://blog.csdn.net/wzy_1988/article/details/45744067
 */

using namespace std;
struct TrieNode {
    // 一开始这里没初始化，导致leetcode无法AC,难道leetcode把这个isWord会初始化为True?
    bool isWord = false;
    unordered_map<char, TrieNode*> nexts;
    TrieNode() {}
};
class Trie {
public:
    TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->nexts.find(c) == p->nexts.end()) p->nexts.insert(make_pair(c, new TrieNode()));
            p = p->nexts[c];
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->nexts.find(c) == p->nexts.end()) return false;
            p = p->nexts[c];
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto c : prefix) {
            if (p->nexts.find(c) == p->nexts.end()) return false;
            p = p->nexts[c];
        }
        return true;
    }
};

int main () {
    // Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert("ab");
    cout << obj->search("a") << endl;
    cout << obj->startsWith("a") << endl;
    return 0;
}
