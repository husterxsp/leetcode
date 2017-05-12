#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct TrieNode {
    bool isWord = false;
    unordered_map<char, TrieNode*> nexts;
    TrieNode() {}
};

class WordDictionary {
public:
    TrieNode* root = new TrieNode();
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->nexts.find(c) == p->nexts.end()) p->nexts.insert(make_pair(c, new TrieNode()));
            p = p->nexts[c];
        }
        p->isWord = true;
    }

    bool searchWord(TrieNode* p, string word, int index) {
        if (index >= word.size()) {
            if (p->isWord) return true;
            return false;
        }

        if (word[index] == '.') {
            for (auto itor : p->nexts) {
                if (searchWord(itor.second, word, index + 1)) {
                    return true;
                }
            }
            return false;
        }
        else if (p->nexts.find(word[index]) != p->nexts.end()) {
            return searchWord(p->nexts[word[index]], word, index + 1);
        }
        else {
            return false;
        }
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(root, word, 0);
    }
};

int main () {
    WordDictionary obj = WordDictionary();
    obj.addWord("bad");
    obj.addWord("dad");
    obj.addWord("mad");

    cout << obj.search("pad") << endl;
    cout << obj.search("bad") << endl;
    cout << obj.search(".ad") << endl;
    cout << obj.search("b..") << endl;

    return 0;
}
