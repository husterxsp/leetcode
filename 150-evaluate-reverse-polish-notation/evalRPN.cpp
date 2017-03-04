#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
bool isOperation (string s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}
int evaluate(int x, int y, string s) {
    if (s == "+") return x + y;
    if (s == "-") return x - y;
    if (s == "*") return x * y;
    if (s == "/") return x / y;
    return 0;
}
int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (int i = 0; i < tokens.size(); i++) {
        if (isOperation(tokens[i])) {
            int y = s.top();
            s.pop();
            int x = s.top();
            s.pop();
            s.push(evaluate(x, y, tokens[i]));
        }
        else {
            // stoi 是C++
            // atoi 是C
            s.push(stoi(tokens[i]));
        }
    }
    return s.top();
}
int main() {
    vector<string> tokens = {"2", "1", "-", "3", "*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}
