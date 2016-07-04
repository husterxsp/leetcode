#include <iostream>
#include <string>
using namespace std;

string intToRoman(int num) {
    int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string result = "";
    int i = 0, times;
    while (num > 0) {
        times = num / nums[i];
        num %= nums[i];
        while (times--) {
            result += romans[i];
        };
        i++;
    }
    return result;
}

int main() {
    cout<<intToRoman(1)<<endl;
    return 0;
}