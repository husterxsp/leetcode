#include <iostream>
#include <vector>

using namespace std;

// 跟斐波拉切数列类似。。。。
int climbStairs(int n) {
    vector<int> ways(n+5,0);
    ways[1]=1, ways[2]=2;
    for(int i=3;i<=n;i++){
        ways[i] = ways[i-1]+ways[i-2];
    }
    return ways[n];
}

int main()
{
    cout << climbStairs(4);
    return 0;
}

