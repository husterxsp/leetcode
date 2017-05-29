#include <iostream>

using namespace std;
string addStrings(string num1, string num2) {
    int n1 = num1.size() - 1, n2 = num2.size() - 1, carry = 0, sum = 0;
    string ret = "";
    while (n1 >= 0 || n2 >= 0) {
        sum = carry;
        sum += n1 >= 0 ? num1[n1--] - '0' : 0;
        sum += n2 >= 0 ? num2[n2--] - '0' : 0;
        carry = sum / 10;
        ret = to_string(sum % 10) + ret;
    }
    if (carry) ret = to_string(carry) + ret;
    return ret;
}
int main() {
    cout << addStrings("9", "9") << endl;
    return 0;
}
