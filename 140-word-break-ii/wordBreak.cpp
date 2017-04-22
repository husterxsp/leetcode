#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void getAllSolutions(int start, int len, const string& s, const unordered_set<string> &dict, string& result, vector<string>& solutions, vector<bool> &possible) {
    if (start == len) {
        solutions.push_back(result.substr(0, result.size() - 1));
        return;
    }
    for (int i = start; i < len; i++) {
        string piece = s.substr(start, i - start + 1);
// 测试
//        if (dict.find(piece) != dict.end() && !possible[i + 1]) {
//            cout << 'a' << endl;
//        }
        if (dict.find(piece) != dict.end() && possible[i + 1]) {
            result.append(piece).append(" ");

            int beforeSize = solutions.size();

            getAllSolutions(i + 1, len, s, dict, result, solutions, possible);

            if (solutions.size() == beforeSize) {
                possible[i + 1] = false;
            }

            result.resize(result.size() - piece.size() - 1);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set <string> dict;

    for (int i = 0; i < wordDict.size(); i++) {
        dict.insert(wordDict[i]);
    }
    int len = s.size();
    string result = "";
    vector<bool> possible(len + 1, true);
    vector<string> solutions;

    getAllSolutions(0, len, s, dict, result, solutions, possible);
    return solutions;
}

int main(){
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> list = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    wordBreak(s, list);
    return 0;
}
