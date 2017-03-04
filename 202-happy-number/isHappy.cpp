#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>
#include <unordered_set>


using namespace std;
bool isHappy(int n) {
    unordered_map<int, int> myMap;
    unordered_set<int> mySet;
    while (n != 1) {
        int sum = 0;
        mySet.insert(n);
        while (n) {
            int tmp = n % 10;
            n /= 10;
            if (!myMap.count(tmp)) {
                myMap[tmp] = tmp * tmp;
            }
            sum += myMap[tmp];
        }
        n = sum;
        if (mySet.count(n)) return false;
    }
    return true;
}
int main () {
    cout << isHappy(1) << endl;
    return 0;
}
