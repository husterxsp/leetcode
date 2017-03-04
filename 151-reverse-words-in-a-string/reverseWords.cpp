#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <Map>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <unordered_set>

using namespace std;
void reverseWords(string &s) {
    if (s.empty()) return;
    string ret = "", word = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == ' ') {
            if (word.size()) {
                reverse(word.begin(), word.end());
                ret.append(word + " ");
                word.clear();
            }
        }
        else {
            word.push_back(s[i]);
        }
    }
    if (word.size()) {
        reverse(word.begin(), word.end());
        ret.append(word);
    }
    else if(!ret.empty()) {
        ret.pop_back();
    }
    s = ret;
}

int main() {
    string s = " ";
    reverseWords(s);
    return 0;
}
