#include <iostream>
#include <vector>
using namespace std;

string addBinary(string a, string b) {
    string ret = "";
    int i = a.length()-1, j=b.length()-1;
    int carry = 0, digit;
    while (i>=0 && j>=0) {
        int tmp = carry+a[i--]-'0'+b[j--]-'0';
        carry = tmp/2;
        digit = tmp%2;
        ret.push_back(digit+'0');
    }
    while (i>=0) {
        int tmp = carry+a[i--]-'0';
        carry = tmp/2;
        digit = tmp%2;
        ret.push_back(digit+'0');
    }
    while (j>=0) {
        int tmp = carry+b[j--]-'0';
        carry = tmp/2;
        digit = tmp%2;
        ret.push_back(digit+'0');
    }
    if(carry){
        ret.push_back('1');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    cout << addBinary("11", "1") << endl;
    return 0;
}