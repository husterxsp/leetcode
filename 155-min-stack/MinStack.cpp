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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (stack.size() == 0) {
            min = x;
        }
        else if (x < min) {
            min = x;
        }
        stack.push_back(x);
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back();
    }

    int getMin() {
        return min;
    }
private:
    int min;
    vector<int> stack;
};

int main () {
    MinStack obj = new MinStack();
    obj.push(x);
    obj.pop();
    int param_3 = obj.top();
    int param_4 = obj.getMin();
    return 0;
}
