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
/** 思路：两个栈。多一个栈存最小值，
 之前想只用一个整数存最小值，没考虑到最小值被pop的情况。
 wrong answer 1:
     obj->push(0);
     obj->push(1);
     obj->push(0);
     obj->getMin();
     obj->pop();
     obj->getMin();
*/
class MinStack {
public:
    stack<int> min;
    stack<int> num;
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        // 注意此处是 <= 而不是 < ，对应wrong answer1
        if (min.empty() || x <= min.top()) min.push(x);
        num.push(x);
    }

    void pop() {
        if (num.top() == min.top()) min.pop();
        num.pop();
    }

    int top() {
        return num.top();
    }

    int getMin() {
        return min.top();
    }
};

int main () {
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);
    obj->getMin();
    obj->pop();
    obj->getMin();
    return 0;
}
