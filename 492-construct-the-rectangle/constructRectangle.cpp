#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;
/*
这题太简单，忽略
*/
vector<int> constructRectangle(int area) {
    vector<int> ret;
    for (int i = sqrt(area); i >= 1; i--) {
        if (area % i != 0) continue;
        ret.push_back(area / i);
        ret.push_back(i);
        break;
    }

    return ret;
}
int main() {
    constructRectangle(4);
    return 0;
}
