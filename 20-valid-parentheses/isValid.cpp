#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack <int> myStack;
    for (int i = 0; i < s.length(); i++) {
        char value = s.at(i);
        cout<< value<<endl;
        if (value == '(' || value == '{' || value == '[') {
            myStack.push(value);
        } else {
            cout<<myStack.size()<<endl;
            char left = myStack.top();
            cout<<myStack.size()<<endl;
            char right = s.at(i);
            if (!((left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']'))) {
                return false;
            }else{
                myStack.pop();
            }
        }
    }
    if (myStack.size() == 0) {
        return true;
    } else {
        return false;
    }
}

int main(){
    string s = "{[{}]}";
    cout<<isValid(s)<<endl;
    return 0;
}