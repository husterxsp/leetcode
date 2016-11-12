#include <iostream>
#include <vector>
#include <Map>
using namespace std;

vector<string> ret;

void getIPAddress(string s, string cur, int step) {
    if(step == 4){
        if(s.length() == 0){
            ret.push_back(cur);
        } else{
            return;
        }
    }
    int num = 0;
    for(int i=0;i<3 && i<s.length();i++){
        num = num*10+s[i]-'0';
        string curTmp = "";
        if(num == 0){
            
        }
        if(num <= 255){
            if(cur == ""){
                curTmp = cur+s.substr(0, i+1);
            } else {
                curTmp = cur+'.'+s.substr(0, i+1);
            }
            getIPAddress(s.substr(i+1), curTmp, step+1);
            //注意一下部分，有0的情况
            if(num == 0){
                break;
            }
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    getIPAddress(s, "", 0);
    cout << ret[0] << endl;
    cout << ret[1] << endl;
    return ret;
}

int main()
{
    restoreIpAddresses("010010");
    return 0;
}
