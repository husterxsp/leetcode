#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;
/**
解法1 超时 44/54
另外不知道为啥这里用unordered_map 会报错？？
*/

map<vector<int>, int> myMap;
int superPow(int a, vector<int>& b) {
    a %= 1337;
    if (b.size() == 1) {
        if (b[0] == 0) return 1;
        if (b[0] == 1) return a;
    }

    if (myMap.find(b) != myMap.end()) return myMap[b];

    vector<int> bHalf;
    int quotient = 0, remain = 0;
    for (auto num : b) {
        quotient = (num + remain * 10) / 2;
        remain = (num + remain * 10) % 2;

        if (!quotient && bHalf.empty()) continue;
        bHalf.push_back(quotient);
    }

    if (!remain) {
        myMap[b] = superPow(a, bHalf) * superPow(a, bHalf) % 1337;
    }
    else {
        myMap[b] = a * superPow(a, bHalf) % 1337 * superPow(a, bHalf) % 1337;
    }

    return myMap[b];
}
/**
解法2,对数组b中每个元素都同时按位乘
*/
int pow(int x, int n) {
    if (n == 0) return 1;
    if (n == 1) return x;
    return pow(x, n / 2) * pow(x, n - n / 2) % 1337;
}
int superPow(int a, vector<int>& b) {
    int ret = 1;
    a %= 1337;
    for (auto num : b) {
        ret = pow(ret, 10) * pow(a, num) % 1337;
    }
    return ret;
}

int main() {
    vector<int> b = {1,0,0,1};
    cout << superPow(2, b) << endl;
    return 0;
}
