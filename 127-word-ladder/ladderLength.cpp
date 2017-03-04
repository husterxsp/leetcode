#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 思路：图的最短路径
// 查找邻居节点
vector<string> find(string s, unordered_set<string>& dict) {
    vector<string> ret;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        for (int j = 0; j < 26; j++) {
            if (c == 'a' + j) continue;
            s[i] = 'a' + j;
            if (dict.count(s)) {
                ret.push_back(s);
                dict.erase(s);
            }
        }
        s[i] = c;
    }
}

// 广度优先搜索 queue
//说是图，但是画出来之后也比较像树，层序遍历
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    wordlist.insert(endWord);
    queue<pair(string, int)> myQueue;
    myQueue.push(make_pair(beginWord, 1));
    while (!myQueue.empty()) {
        string s = myQueue.front().first;
        int layer = myQueue.front().second;
        if (s == endWord) {
            return layer;
        }
        myQueue.pop();
        vector<string> neighbors = find(s, wordList);
        for (int i = 0; i < neighbors.size(); i++) {
            myQueue.push(make_pair(s, layer + 1));
        }
    }
    return 0;
}

int main(){
    unordered_set<string> wordlist = {"hot","dot","dog","lot","log"};
    cout << findLadders("hit", "cog", wordlist);
    return 0;
}
