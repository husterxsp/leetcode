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
int find(vector<int>& numbers, int start, int target) {
    int ret;
    int left = start, right = numbers.size() - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (numbers[mid] == target) return mid;
        if (numbers[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return 0;
}
vector<int> twoSum(vector<int>& numbers, int target) {
    vector<int> ret = {0, 0};
    for (int i = 0; i < numbers.size(); i++) {
        int index2 = find(numbers, i + 1, target - numbers[i]);
        ret[0] = i + 1;
        ret[1] = index2 + 1;
        if (index2) break;
    }
    return ret;
}

int main () {
    vector<int> numbers = {1, 2, 3, 4, 4, 9, 56, 90};
    twoSum(numbers, 8);
    return 0;
}
