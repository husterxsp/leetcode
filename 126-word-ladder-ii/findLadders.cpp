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
vector<vector<string>> ret;
unordered_set<std::string>::const_iterator got;

void bfs(string beginWord, string endWord, unordered_set<string> &wordList, vector<string> arr, int len) {\
    string curStr = arr[arr.size()-1];
    if(curStr.compare(endWord) == 0){
        ret.push_back(arr);
        return;
    }
    for(int i=0;i<len;i++){
        string curTmp = curStr;
        char c = 'a'-1;
        for(char c='a';c<='z';c++){
            curTmp[i] = c;
            if(find(arr.begin(), arr.end(), curTmp) != arr.end()) continue;
            if(wordList.find(curTmp) == wordList.end()) continue;
            arr.push_back(curTmp);
            bfs(beginWord, endWord, wordList, arr, len);
            arr.pop_back();
        }
    }

}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
    vector<string> arr = {beginWord};
    bfs(beginWord, endWord, wordList, arr, beginWord.size());
    return ret;
}

int main(){
    unordered_set<string> list = {"hot","dot","dog","lot","log"};
    cout << findLadders("hit", "cog", list).size();
    return 0;
}
