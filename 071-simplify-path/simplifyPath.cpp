#include <iostream>
#include <vector>

using namespace std;

// 这种题我也是醉了。。。

string goback(string str){
    if(str == "/"){
        return "/";
    }
    str.pop_back();
    for(int i=str.length()-1;i>=1;i--){
        if(str[i] == '/'){
            str.pop_back();
            break;
        }
        str.pop_back();
    }
    return str;
}

string simplifyPath(string path) {
    string ret = "/";
    for(int i=1;i<path.length();i++){
        string type = path.substr(i, 2);
        if(type == "./"){
            i++;
            continue;
        } else if(type == "..") {
            i+=2;
            ret = goback(ret);
            continue;
        }
        if(ret.back() == '/' && path[i] == '/'){
            continue;
        }
        if(path[i] == '.' && path[i+1] != '.'){
            continue;
        }
        ret.push_back(path[i]);
    }
    if(ret.length() > 1 && ret.back() == '/'){
        ret.pop_back();
    }
    return ret;
}

int main()
{
    cout << simplifyPath("/...");
    return 0;
}

