#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
string getHint(string secret, string guess) {
    unordered_map<char, unordered_set<int>> secretMap;

    for (int i = 0; i < secret.size(); i++) {
        secretMap[secret[i]].insert(i);
    }

    int a = 0, b = 0;
    for (int i = 0; i < guess.size(); i++) {

    }
}

int main() {

    return 0;
}
