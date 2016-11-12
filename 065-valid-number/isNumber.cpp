#include <iostream>
#include <vector>

using namespace std;
//恩，这题让我又翻出了一年前写的编译原理的课设，词法语法分析器。。。
//数字：( +|-|ε ) dd*(.dd* | ε)( e ( +|-|ε ) dd*|ε)
//提交了好多次，“ ”，“.”,"36.e3"没注意，而“3.”，“01”leetcode都算对, "e9"算错？？？ ,“ e9”,"-e58"
//暂未AC,搁置。各种情况太多，leetcode又没法说明哪些是对的
// 考虑从反面考虑，有错就return false;
bool isNumber(string s) {
    bool isFirst = true;
    bool hasPoint = false;
    bool hasE  = false;
    bool hasZero = false;
    int i=0;
    char ch = ' ';
    int n = s.length();
    while (s[i] == ' ')i++;
    if(i == n)return false;
    for(;i<n;i++){
        ch = s[i];
        switch (ch) {
            case '+':
            case '-':
                if(!(isFirst || s[i-1]=='e')) return false;
                if(i<n-2 && !isdigit(s[i+1])) return false;
                break;
            case '.':
                if(!hasE && !hasPoint){
                    if(isFirst){
                        if(i<n-1 && isdigit(s[i+1])){
                            hasPoint = true;
                        }else {
                            return false;
                        }
                    } else {
                        if(s[i-1]=='+' ||s[i-1]=='-'){
                            if(i<n-1 && isdigit(s[i+1])){
                                hasPoint = true;
                            }else {
                                return false;
                            }
                        }else if(isdigit(s[i-1])){
                            hasPoint = true;
                        }else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
                break;
            case 'e':
                if(!hasE && !isFirst) {
                    if(i<n-2 && (s[i+1]=='+'||s[i+1]=='-') && isdigit(s[i+2])){
                        hasE = true;
                    } else if(i<n-1 && isdigit(s[i+1])){
                        hasE = true;
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
                break;
            case ' ':
                while (i < n && s[i] == ' ') i++;
                if(i != n) return false;
                break;
            default:
                if(!isdigit(ch))return false;
        }
        isFirst = false;
    }
    return true;
}

int main() {

    string str = " -e58";
    cout << isNumber(str) << endl;
    return 0;
}
