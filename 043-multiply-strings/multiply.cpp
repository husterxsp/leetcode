#include <iostream>
#include <vector>

using namespace std;

string multiply(string num1, string num2) {
    if(num1.empty() || num2.empty()){
        return "";
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    // 字符串res 初始化
    string res(num1.size()+num2.size(), '0');
    for(int j=0;j<num2.size();j++){
        int carry = 0;
        int value = num2[j]-'0';
        for(int i=0;i<num1.size();i++){
            carry += (num1[i]-'0')*value + (res[i+j]-'0');
            res[i+j] = carry%10 + '0';
            carry /= 10;
        }
        if(carry != 0){
            res[num1.size()+j] = carry + '0';
        }
    }
    reverse(res.begin(), res.end());
    int count = 0;
    while(count < res.size() && res[count] == '0'){
        count++;
    }
    res.erase(0, count);
    if(res == ''){
        res = '0';
    }
    return res;
}

int main() {
    cout << multiply("1", "2");
    return 0;
}