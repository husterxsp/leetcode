#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


string countAndSay(int n) {
    if(n == 0){
        return "";
    }
    string prev = "1";
    for(int i=2; i<=n;i++){
        int count = 1;
        char curChar = prev[0];
        string curStr = "";
        prev += '#';
        for(int j=1;j<prev.length();j++){
            if(prev[j] == curChar){
                count++;
            } else {
                curStr += to_string(count);
                curStr += curChar;
                curChar = prev[j];
                count = 1;
            }
        }
        prev = curStr;
    }
    return prev;
}

int main(){
    cout << countAndSay(4);
}
