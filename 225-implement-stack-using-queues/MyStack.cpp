#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class MyStack {
public:
    queue<int> myQueue;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> tmp;
        while (!myQueue.empty()) {
            tmp.push(myQueue.front());
            myQueue.pop();
        }
        myQueue.push(x);
        while (!tmp.empty()) {
            myQueue.push(tmp.front());
            tmp.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = myQueue.front();
        myQueue.pop();
        return ret;
    }

    /** Get the top element. */
    int top() {
        return myQueue.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return myQueue.empty();
    }
};

int main () {
    MyStack obj = MyStack();
    obj.push(1);
    cout << obj.pop() << endl;
    cout << obj.top() << endl;
    cout << obj.empty() << endl;

    return 0;
}
