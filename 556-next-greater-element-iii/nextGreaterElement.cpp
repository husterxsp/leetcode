class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len = s.size();

        stack<int> myStack;
        int i, j;
        for (i = len - 1; i >= 0; i--) {
            if (myStack.empty() || s[i] >= s[myStack.top()]) myStack.push(i);
            else {
                while (!myStack.empty() && s[i] < s[myStack.top()]) {
                    j = myStack.top();
                    myStack.pop();
                }
                break;
            }
        }
        if (i == -1) return -1;

        char c = s[i];
        s[i] = s[j];
        s[j] = c;
        sort(s.begin() + i + 1, s.end());

        // 注意溢出的情况。input: 1999999999
        return stol(s) > INT_MAX ? -1 : stoi(s);
    }
};
