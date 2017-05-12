#include <iostream>
#include <vector>

/**
数学题，找规律
列举出一些n比较小的输出结果
*/
using namespace std;
//解法1，超时 99999
int bulbSwitch(int n) {
   int ret = 0;
   for (int i = 1; i <= n; i++) {
       int t = 0;
       for (int j = 2; j <= i; j++) {
           if (i % j == 0) t++;
       }
       if (t % 2 == 0) ret++;
   }
   return ret;
}
// 解法2 AC
int bulbSwitch(int n) {
    int ret = 0;
    while (ret * ret < n) {
        ret++;
    }
    return ret * ret > n ? ret - 1 : ret;
}

int main() {
    for (int i = 0; i < 1000; i++) {
        cout << to_string(i) + "-> " << bulbSwitch(i) << endl;
    }

    return 0;
}
