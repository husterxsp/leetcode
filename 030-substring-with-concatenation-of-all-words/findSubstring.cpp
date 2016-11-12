#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

// 注意边界条件！！！传入空值及循环结束条件
bool checkSubstring(string s, unordered_map<string, int> wordList, int wordCount, int wordLen, int index){
    for(int i=0;i<wordCount;i++){
        string str = s.substr(index, wordLen);
        if(wordList.count(str) > 0 && wordList[str] > 0) {
            wordList[str]--;
            index += wordLen;
        } else {
            return false;
        }
    }
    return true;
}
vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> ret;
    if(!words.size()) return ret;
    unordered_map<string, int> wordList;
    int wordLen = words[0].size();
    int wordCount = words.size();
    int totalLen = wordLen*wordCount;
    if(s.length() < totalLen) return ret;
    for(int i=0;i<wordCount;i++){
        wordList[words[i]]++;
    }
    for(int i=0;i<=s.length()-totalLen;i++){
        if(checkSubstring(s, wordList, wordCount, wordLen, i)){
            ret.push_back(i);
        }
    }
    return ret;
}

int main(){
    vector<string> words = {"word","good","best","good"};
    findSubstring("wordgoodgoodgoodbestword", words);
    return 0;
}
