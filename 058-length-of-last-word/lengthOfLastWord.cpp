#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    int ret=0;
    bool space = false;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' '){
            space = true;
            continue;
        }
        if(space){
            ret = 1;
            space = !space;
            continue;
        }
        ret++;
    }

    return ret;
}

int main(){
    string s;
    getline(cin, s);
    cout << lengthOfLastWord(s) << endl;
    return 0;
}