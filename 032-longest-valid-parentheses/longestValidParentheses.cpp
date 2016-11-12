#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

int longestValidParentheses(string s) {
    if(s.length() == 0 || s.length() == 1){
        return 0;
    }
    int res = 0, cur = 0, start = -1;
    vector<int> stack;
    
    for(int i=0;i < s.length(); i++) {
        if(s[i] == '('){
            stack.push_back(i);
        } else if(s[i] == ')' && stack.size()){
            stack.pop_back();
            if(stack.size()){
                res = (i - stack.back())>res ? (i - stack.back()) : res;
            } else {
                res = (i - start)>res ? (i - start) : res;
            }
        } else {
            start = i;
        }
    }
    return res;
}

int main(){
    cout << longestValidParentheses("()(()");
    return 0;
}
