#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>
#include <unordered_map>

/**
 1. 注意溢出
 2. 注意正负
 3. 怎么取得小数部分？先乘10再除

 */
using namespace std;
string fractionToDecimal(int numerator, int denominator) {
    int flag = numerator < 0 ? -1 : 1;
    flag *= denominator < 0 ? -1 : 1;

    //  WA: -1 / -2147483648, 注意这个取绝对值，先转换为long
    long num = abs((long)numerator);
    long den = abs((long)denominator);

    long quotient = num / den;
    long remain = num % den;

    string ret = to_string(quotient);
    //  WA: 0 / -5 => "-0"
    if (flag < 0 && (quotient > 0 || remain > 0)) ret = "-" + ret;

    if (remain == 0) return ret;

    ret += ".";

    int pos = 0;
    string s = "";
    unordered_map<long, int> myMap;

    while (remain != 0) {
        if (myMap.find(remain) != myMap.end()) {
            s.insert(myMap[remain], "(");
            s += ")";
            // 此处的return是找到了循环部分
            return ret + s;
        }

        myMap[remain] = pos;

        s += to_string(remain * 10 / den);
        remain = remain * 10 % den;
        pos++;
    }
    // 此处的return 是刚好除尽
    return ret + s;
}

int main () {
    cout << fractionToDecimal(-1, -2147483648) << endl;
    return 0;
}
