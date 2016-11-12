#include <iostream>
using namespace std;

int mySqrt(int x) {
    if(x==0 || x == 1){
        return x;
    }
    int ret;
    int left=1, right=x, mid;
    while (left+1 < right) {
        mid = (left+right)/2;
        if(mid*mid == x){
            left = mid;
            break;
        }
        if(mid*mid > x){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    if(right*right <= x){
        return right;
    }
    return left;
}

int main()
{
    cout << mySqrt(8);
    return 0;
}

