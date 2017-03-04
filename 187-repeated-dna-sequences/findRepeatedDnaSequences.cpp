#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#include <Map>
#include <Set>
#include <unordered_map>

using namespace std;
/**
    遇到一点坑
    cout << s.length() << endl;
    cout << 0 - 9 << endl;
    cout << s.length() - 9 << endl; 此处为啥不对？
    因为s.length()返回的类型是无符号整型？
*/
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string, int> myMap;
    vector<string> ret;

    for (int i = 0; i < s.length(); i++) {
        string str = s.substr(i, 10);
        if (!myMap.count(str)) {
            myMap[str] = 1;
        }
        else {
            myMap[str]++;
        }
    }
    for(auto i : myMap) {
        if (i.second > 1) {
            ret.push_back(i.first);
        }
    }
    return ret;
}

int main () {
    findRepeatedDnaSequences("");
    return 0;
}
