#include <iostream>
#include <vector>
#include <Map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 题目不是太难，但是需要考虑各种情况才能AC,编码前应该想清楚。
// 1.主函数三种情况 == ，<，>
// 2.getString函数中的多种情况。
string getString(vector<string>& words, int wordNum, int pos, int curWidth, int maxWidth){
    // 单个单词，靠左
    if(wordNum == 1){
        while (curWidth < maxWidth) {
            words[pos].push_back(' ');
            curWidth++;
        }
        string str = words[pos];
        return words[pos];
    }
    // 最后一行靠左
    if(pos == words.size()-1){
        while (curWidth < maxWidth) {
            words[pos].push_back(' ');
            curWidth++;
        }
    } else {
        // 分别插入' '
        while (curWidth < maxWidth) {
            for(int i=pos-wordNum+1 ;i<pos;i++){
                words[i].push_back(' ');
                curWidth++;
                if(curWidth >= maxWidth){
                    break;
                }
            }
        }
    }
    // 拼接
    string str = "";
    for(int i=pos-wordNum+1;i<pos;i++){
        str += words[i] + ' ';
        if(i == pos-1){
            str += words[pos];
        }
    }
    return str;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> ret;
    int curWidth = 0;
    int wordNum = 0;
    
    for(int i=0;i<words.size();i++){
        if(curWidth == 0){
            curWidth += words[i].length();
        } else {
            curWidth += 1+words[i].length();
        }
        wordNum++;
        if(curWidth == maxWidth){
            ret.push_back(getString(words, wordNum, i, curWidth, maxWidth));
            curWidth = 0;
            wordNum = 0;
        } else if(curWidth > maxWidth){
            curWidth = curWidth-1-words[i].length();
            ret.push_back(getString(words, --wordNum, --i, curWidth, maxWidth));
            curWidth = 0;
            wordNum = 0;
        } else {
            if(i == words.size()-1){
                ret.push_back(getString(words, wordNum, i, curWidth, maxWidth));
            }
        }

    }
    
    return ret;
}

int main()
{
    vector<string> str = {"What","must","be","shall","be."};
//    vector<string> str = {""};
    fullJustify(str, 12);
    return 0;
}
