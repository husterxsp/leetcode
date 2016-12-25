#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <unordered_set>

using namespace std;

int compareVersion(string version1, string version2) {
    int i = 0, j = 0, m = version1.length(), n = version2.length(), num1 = 0, num2 = 0;

    while (i < m || j < n) {
        while (version1[i] != '.' && i < m) {
            num1 = num1 * 10 + version1[i] - '0';
            i++;
        }
        while (version2[j] != '.' && j < n) {
            num2 = num2 * 10 + version2[j] - '0';
            j++;
        }

        if (num1 > num2) {
            return 1;
        }
        else if (num1 < num2) {
            return -1;
        }
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}

int main() {
    cout << compareVersion("1", "1.1.1") << endl;
    return 0;
}
