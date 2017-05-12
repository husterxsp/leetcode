#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/*
AC, 思路就是用x,y互相加减，然后得出的新的数再和x,y互相加减
就是效率有点低，322ms
*/
bool canMeasureWater(int x, int y, int z) {
    deque<int> myQueue;
    unordered_set<int> mySet;

    myQueue.push_back(x);
    myQueue.push_back(y);

    mySet.insert(x);
    mySet.insert(y);

    vector<int> oper = {x, y, -x, -y};
    while (!myQueue.empty()) {
        int water = myQueue.front();
        myQueue.pop_front();

        for (auto o : oper) {
            int tmp = abs(water + o);
            if (tmp > x + y) continue;

            if (mySet.find(tmp) == mySet.end()) {
                mySet.insert(tmp);
                myQueue.push_back(tmp);
            }
        }

        if (mySet.find(z) != mySet.end()) return true;
    }
    return false;
}

int main() {
    cout << canMeasureWater(2,6,5) << endl;
    return 0;
}
