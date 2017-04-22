#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>
#include <cstring>
#include <string.h>

using namespace std;
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<NestedInteger> list;
    NestedIterator(vector<NestedInteger> &nestedList) {
        list = nestedList;
        reverse(list.begin(), list.end());
    }

    int next() {
        NestedInteger t = list.back();
        list.pop_back();
        return t.getInteger();
    }

    bool hasNext() {
        while (!list.empty()) {
            NestedInteger t = list.back();
            if (t.isInteger()) return true;
            list.pop_back();
            for (int i = t.getList().size() - 1; i >= 0; i--) {
                list.push_back(t.getList()[i]);
            }
        }
        return false;
    }
};
