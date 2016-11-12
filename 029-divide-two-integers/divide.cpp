#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

// 任何一个正整数都可以用 2 的幂次方表示。。。。。
int divide(int dividend, int divisor) {
    if(divisor == 0) return dividend>=0 ? INT_MAX : INT_MIN;
    if(dividend==INT_MIN && divisor==-1) return INT_MAX;
    
    bool isNeg = false;
    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) isNeg = true;
    unsigned long long dvd = abs((long long)dividend);
    unsigned long long dvs = abs((long long)divisor);
    unsigned long long dvs_original = dvs;
    
    int i = 0;
    while(dvs<<(i+1) <= dvd){
        i++;
    }
    
    int res = 0;
    while(dvd >= dvs_original) {
        if(dvd >= dvs<<i) {
            dvd -= dvs<<i;
            res += 1<<i;
        }
        i--;
    }
    return isNeg ? 0-res : res;
}

int main(){
    cout << divide(32, 3);
    return 0;
}