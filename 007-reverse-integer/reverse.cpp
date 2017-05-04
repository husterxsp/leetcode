#include <iostream>
#include <vector>

using namespace std;
int reverse(int x) {
    int flag = 1;
    if (x < 0) flag = -1;
    x = abs(x);

    string s = to_string(x);
    string copy(s);
    reverse(copy.begin(), copy.end());
    long ret = stol(copy) * flag;
    return ret < INT_MIN || ret > INT_MAX ? 0 : ret;
}
int main() {
    cout << reverse(1000000003) << endl;
    return 0;
}
