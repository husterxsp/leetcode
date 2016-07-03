#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

long myAtoi(char* str) {
    long num;
    num = atol(str);
    if(num>INT_MAX){
        return INT_MAX;
    }else if(num<INT_MIN){
        return INT_MIN;
    }
    return num;
}

int main() {
    char *str = "2147483648";
    printf("%ld\n", myAtoi(str));
    return 0;
}
