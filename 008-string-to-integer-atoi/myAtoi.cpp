#include <iostream>
#include <vector>

using namespace std;
int myAtoi(string str) {

    int ret = 0, i = 0, flag = 1;

    // whitespaces
    while (str[i] == ' ') i++;

    // sign of the number
    if (str[i] == '-' || str[i] == '+') {
        flag = 1 - 2 * (str[i++] == '-');
    }

    while (str[i] >= '0' && str[i] <= '9') {

        // overflow
        if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
            return flag > 0 ? INT_MAX : INT_MIN;
        }

        ret = ret * 10 + str[i++] - '0';
    }

    return ret * flag;
}

int main() {
    cout << myAtoi("     2121") << endl;
    return 0;
}
