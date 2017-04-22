#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class MyQueue {
public:
    stack<int> myStake;
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> tmp;
        while (!myStake.empty()) {
            tmp.push(myStake.top());
            myStake.pop();
        }
        myStake.push(x);
        while (!tmp.empty()) {
            myStake.push(tmp.top());
            tmp.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = myStake.top();
        myStake.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return myStake.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return myStake.empty();
    }
};

int main () {
    MyQueue obj = MyQueue();
    obj.push(1);
    obj.push(2);
    cout << obj.pop() << endl;
    cout << obj.peek() << endl;
    cout << obj.empty() << endl;
    return 0;
}
