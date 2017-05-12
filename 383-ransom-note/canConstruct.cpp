#include <iostream>
#include <unordered_map>

using namespace std;
bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> myMap;
    for (auto c : magazine) myMap[c]++;
    for (auto c : ransomNote) {
        myMap[c]--;
        if (myMap[c] < 0) return false;
    }
    return true;
}

int main() {
    cout << canConstruct("aa", "aab") << endl;
    return 0;
}
