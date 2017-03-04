// #include <iostream>
// #include <vector>
// #include <queue>
// #include <string>
// #include <stack>
// #include <Map>
// #include <Set>
// #include <unordered_map>
// #include <unordered_set>
// #include <strstream>
//
// using namespace std;
// string c2str(char c) {
//     strstream stream;
//     stream << c;
//     return stream.str();
// }
// int calculate(string s) {
//     vector<string> reversePolish;
//     stack<char> operatorStack;
//     for (int i = 0; i < s.length(); i++) {
//         cout << s[i] << endl;
//         if (s[i] == ' ') continue;
//         if (s[i] == '(') {
//             operatorStack.push(s[i]);
//         }
//         else if (s[i] == ')') {
//             while (operatorStack.top() != '(') {
//                 reversePolish.push_back(c2str(operatorStack.top()));
//                 operatorStack.pop();
//             }
//             operatorStack.pop();
//         }
//         else if (s[i] == '+' || s[i] == '-') {
//             if (!operatorStack.empty()) {
//                 char tmp = operatorStack.top();
//                 if (tmp == '+' || tmp == '-') {
//                     reversePolish.push_back(c2str(tmp));
//                     operatorStack.pop();
//                 }
//             }
//             operatorStack.push(s[i]);
//         }
//         else {
//             string num = "";
//             while (s[i] >= '0' && s[i] <= '9' & i < s.length()) {
//                 num += s[i];
//                 i++;
//             }
//             i--;
//             reversePolish.push_back(num);
//         }
//     }
//     while (!operatorStack.empty()) {
//         reversePolish.push_back(c2str(operatorStack.top()));
//         operatorStack.pop();
//     }
//
//     stack<string> ret;
//     reverse(reversePolish.begin(), reversePolish.end());
//     while (!reversePolish.empty()) {
//         string str = reversePolish.back();
//         reversePolish.pop_back();
//         if (str == "+" || str ==  "-") {
//             int right = stoi(ret.top());
//             ret.pop();
//             int left = stoi(ret.top());
//             ret.pop();
//             if (str == "+") {
//                 ret.push(to_string(left + right));
//             }
//             else {
//                 ret.push(to_string(left - right));
//             }
//         }
//         else {
//             ret.push(str);
//         }
//     }
//     return stoi(ret.top());
// }
//
// int main () {
//     cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
//     return 0;
// }
// ----改进--上面的代码，leetcode显示'strstream' was not declared in this scope。。。
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>
#include <strstream>

using namespace std;

int calculate(string s) {
    vector<string> reversePolish;
    stack<string> operatorStack;
    for (int i = 0; i < s.length(); i++) {
        string str(1, s[i]);
        if (str == " ") continue;
        if (str == "(") {
            operatorStack.push(str);
        }
        else if (str == ")") {
            while (operatorStack.top() != "(") {
                reversePolish.push_back(operatorStack.top());
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (str == "+" || str == "-") {
            if (!operatorStack.empty()) {
                string tmp = operatorStack.top();
                if (tmp == "+" || tmp == "-") {
                    reversePolish.push_back(tmp);
                    operatorStack.pop();
                }
            }
            operatorStack.push(str);
        }
        else {
            string num = "";
            while (s[i] >= '0' && s[i] <= '9' && i < s.length()) {
                num += s[i];
                i++;
            }
            i--;
            reversePolish.push_back(num);
        }
    }
    while (!operatorStack.empty()) {
        reversePolish.push_back(operatorStack.top());
        operatorStack.pop();
    }

    stack<string> ret;
    reverse(reversePolish.begin(), reversePolish.end());
    while (!reversePolish.empty()) {
        string str = reversePolish.back();
        reversePolish.pop_back();
        if (str == "+" || str ==  "-") {
            int right = stoi(ret.top());
            ret.pop();
            int left = stoi(ret.top());
            ret.pop();
            if (str == "+") {
                ret.push(to_string(left + right));
            }
            else {
                ret.push(to_string(left - right));
            }
        }
        else {
            ret.push(str);
        }
    }
    return stoi(ret.top());
}

int main () {
    cout << calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}
