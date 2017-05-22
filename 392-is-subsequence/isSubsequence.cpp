#include <iostream>

using namespace std;
/**
 又是边界条件。。s="", t=""
 虽然想到了都为空，但是不知道都为空该返回啥就submit了。。
 另外，这道题只能算easy，没什么可看的
 */
bool isSubsequence(string s, string t) {
    int sn = s.size(), tn = t.size();
    if (sn == 0) return true;

    int index = 0;
    for (int i = 0; i < tn; i++) {
        if (t[i] == s[index]) index++;
        if (index == sn) return true;
    }
    return false;
}

int main() {
    cout << isSubsequence("", "") << endl;
    return 0;
}
