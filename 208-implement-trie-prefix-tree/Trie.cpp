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
    bool isWord;
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
        for (int i = 0; i < word.length(); i++) {
            if (p->nexts.count(word[i])) {
                p = p->nexts[word[i]];
            }
            else {
                p->nexts.insert(make_pair(word[i], new TrieNode()));
                p = p->nexts[word[i]];
            }
        }
        p->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = root;
        for (int i = 0; i < word.length(); i++) {
            if (p->nexts.count(word[i])) {
                p = p->nexts[word[i]];
            }
            else {
                return false;
            }
        }
        return p->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (p->nexts.count(prefix[i])) {
                p = p->nexts[prefix[i]];
            }
            else {
                return false;
            }
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
