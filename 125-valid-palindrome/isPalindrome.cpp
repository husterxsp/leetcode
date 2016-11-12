#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
using namespace std;

bool isPalindrome(string s) {
    int head = 0, tail = s.length()-1;
    while (head <= tail) {
        char h = tolower(s[head]);
        char t = tolower(s[tail]);
        if(!isalnum(h)){
            head++;
            continue;
        }
       if(!isalnum(t)){
            tail--;
            continue;
        }
        if(t != h) return false;
        head++;
        tail--;
    }
    return true;
}

int main(){
    string str = "0p";
    cout << isPalindrome(str);
    return 0;
}
