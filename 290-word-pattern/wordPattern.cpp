#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

/**
    注意需要一一对应

    参考：http://www.cnblogs.com/grandyang/p/4857022.html

     istringstream in(str); 可以用来分割字符串
*/
using namespace std;
bool wordPattern(string pattern, string str) {
    unordered_map<char, string> myMap;
    vector<string> strArr;
    string tmp = "";

    str += " ";
    for (auto c : str) {
        if (c == ' ') {
            strArr.push_back(tmp);
            tmp.clear();
        }
        else {
            tmp += c;
        }
    }

    int n = pattern.size();

    if (n != strArr.size()) return false;
    for (int i = 0; i < n; i++) {
        char c = pattern[i];
        if (myMap.find(c) != myMap.end()) {
            if (strArr[i].compare(myMap[c]) != 0) return false;
        }
        else {
            for (auto itor : myMap) {
                if (strArr[i] == itor.second) return false;
            }
            myMap[c] = strArr[i];
        }
    }
    return true;
}

int main () {
    cout << wordPattern("abba", "g 1 1 g") << endl;
    return 0;
}
