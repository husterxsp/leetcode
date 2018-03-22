// easy
#include <iostream>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <queue>

using namespace std;

vector<int> partitionLabels(string S) {
    map<char, int> myMap;
    for (int i = 0; i < S.size(); i++) {
        char c = S[i];
        if (myMap.find(c) == myMap.end()) myMap[c] = i;
        else myMap[c] = max(myMap[c], i);
    }

    vector<int> ret;
    int end = 0, start = 0;
    for (int i = start; i < S.size(); i++) {
        char c = S[i];
        if (i > end) {
            ret.push_back(end - start + 1);
            start = i;
        }
        end = max(end, myMap[c]);
    }

    if (end >= start) ret.push_back(end - start + 1);

    return ret;
}
int main() {

    partitionLabels("ababcbacadefegdehijhklij");

    return 0;
}
