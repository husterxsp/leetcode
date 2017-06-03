#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
vector<string> findWords(vector<string>& words) {
    unordered_map<char, int> myMap;
    vector<char> row1{'q','w','e','r','t','y','u','i','o','p'},
    row2{'a','s','d','f','g','h','j','k','l'},
    row3{'z','x','c','v','b','n','m'};
    for (char r1 : row1) myMap[r1] = 1;
    for (char r2 : row2) myMap[r2] = 2;
    for (char r3 : row3) myMap[r3] = 3;

    vector<string> ret;
    for (auto str : words) {
        int row = myMap[tolower(str[0])], i = 0;
        for (i = 1; i < str.size(); i++) {
            if (myMap[tolower(str[i])] != row) break;
        }
        if (i == str.size()) ret.push_back(str);
    }
    return ret;
}
int main(){
    vector<string> words{"Alaska","Dad"};
    findWords(words);
    return 0;
}
