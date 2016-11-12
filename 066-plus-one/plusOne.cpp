#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    for(int i=digits.size()-1;i>=0;i--){
        int digit = (digits[i]+carry)%10;
        carry = (digits[i]+carry)/10;
        digits[i] = digit;
        if(carry == 0){
            return digits;
        }
    }
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(){
    vector<int> a = {9,9,9,9};
    cout << plusOne(a).size();
    return 0;
}