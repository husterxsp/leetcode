#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>

using namespace std;
string reverseString(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        int tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
    return s;
}

int main() {
    cout << reverseString("hello") << endl;
    return 0;
}
