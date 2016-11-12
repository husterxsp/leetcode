#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

int reverse(int x) {
    long result = 0;
    if(x < 0) {
        return 0;
    }
    while (x) {
        int digit = x % 10;
        x /= 10;
        result = result * 10 + digit;
    }
    if(result > INT_MAX || result < INT_MIN) {
        return 0;
    } else {
        return (int)result;
    }
}

bool isPalindrome(int x) {
    if (x == reverse(x)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    int num = -2147447412;
    printf("%d\n", isPalindrome(num));
    return 0;
}
