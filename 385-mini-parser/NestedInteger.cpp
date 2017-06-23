#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution {
public:
    NestedInteger deserialize(string s) {
        stack<string> myStack;

        NestedInteger cur, pre;
        int n = s.size();
        string Integer = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                // myStack.push(s.substr(i));
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                Integer += s[i];
            }
            else if (s[i] == ',') {
                if (Integer != "") {
                    myStack.push(Integer);
                    Integer = "";
                }
            }
            else if (s[i] == ']') {
                cur.setInteger(stoi(myStack.top()));
                myStack.pop();

                if (pre.isInteger()) {
                    cur.add(pre);
                    pre = cur;
                    cur = NestedInteger();
                }
            }
        }
        return pre;
    }
};

int main() {
    Solution s = Solution();
    s.deserialize("[123,[456,[789]]]");
    return 0;
}
