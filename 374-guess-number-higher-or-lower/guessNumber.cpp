#include <iostream>
#include <cmath>
#include <vector>

/**
The key point is to read the problem carefully.
-1 : My number is lower
1 : My number is higher
0 : Congrats! You got it!

Here "My" means the number which is given for you to guess not the number you put into guess(int num).
*/

using namespace std;
int guess(int num) {
    if (num < 6) return 1;
    if (num > 6) return -1;
    return 0;
}

int guessNumber(int n) {
    int left = 0, right = n, mid = 0;
    while (left < right) {
        mid = left + (right - left) / 2;
        int tmp = guess(mid);
        if (tmp == -1) right = mid;
        else if (tmp == 1) left = mid + 1;
        else return mid;
    }
    return left;
}

int main() {
    cout << guessNumber(10) << endl;
    return 0;
}
