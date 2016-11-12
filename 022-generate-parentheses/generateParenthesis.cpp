#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

void generate(int left, int right, string parenthesis, vector<string> &result) {
    if (left == 0 && right == 0) {
        result.push_back(parenthesis);
        return;
    }
    if (left > 0) {
        generate(left - 1, right, parenthesis + '(', result);
    }
    if (right > 0 && right > left) {
        generate(left, right - 1, parenthesis + ')', result);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    generate(n, n, "", result);
    return result;
}


int main(){
    vector<string> result;
    result = generateParenthesis(3);
    for(int i=0; i<result.size(); ++i){
        cout << result[i] << endl;
    }
    return 0;
}