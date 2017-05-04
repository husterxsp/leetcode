#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

/**
 注意这题一个字符可能被多个字符串使用，vis数组的处理
 */
struct TrieNode {
    string word = "";
    map<char, TrieNode*> nexts;
    TrieNode() {}
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* p = root;
        for (auto c : word) {
            if (p->nexts.find(c) == p->nexts.end()) p->nexts.insert(make_pair(c, new TrieNode()));
            p = p->nexts[c];
        }
        p->word = word;
    }
};

void search(vector<vector<char>>& board, vector<vector<int>>& vis, int i, int j, TrieNode* p, vector<string>& ret) {

    if (!p) return;
    if (p->word != "") {
        ret.push_back(p->word);
        p->word.clear();
        // 有一点疑问，search到之后不return?
        // 例如 "abc", "abcd", search到"abc"后还有可能存在"abcd"
        // return;
    }

    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    vis[i][j] = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + dir[d][0];
        int y = j + dir[d][1];

        if(x >= 0 && x < board.size() &&
           y >= 0 && y < board[0].size() &&
           !vis[x][y] && p->nexts[board[x][y]]) {
            search(board, vis, x, y, p->nexts[board[x][y]], ret);
        }
    }
    vis[i][j] = 0;
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> ret;
    if (words.empty() || board.empty() || board[0].empty()) return ret;

    int m = board.size();
    int n = board[0].size();

    Trie* obj = new Trie();
    for (auto word : words) obj->insert(word);

    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            search(board, vis, i, j, obj->root->nexts[board[i][j]], ret);
        }
    }

    return ret;
}

int main() {
    vector<vector<char>> a = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    findWords(a, words);
    return 0;
}
