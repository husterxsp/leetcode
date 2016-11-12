#include <stdio.h>
#include <limits.h>
#include <math.h>

int reverse(int x);

int main() {
    int x = 1000000003;
    printf("%d\n", reverse(x));
    return 0;
}

int reverse(int x) {
    long long result = 0;
    int sign = ( x < 0 ) ? -1 : 1;
    x = abs(x);
    while (x) {
        int digit = x % 10;
        x /= 10;
        result = result * 10 + digit;
    }
    result *= sign;
    if(result > INT_MAX || result < INT_MIN) {
        return 0;
    } else {
        return result;
    }
}