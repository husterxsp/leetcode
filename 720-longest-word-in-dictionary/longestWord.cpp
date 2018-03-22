#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;
bool compare(string& a, string& b) {
    return a.size() < b.size() || a < b;
}
string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(), compare);
    string ret = words[0];
    for (int i = 1; i < words.size(); i++) {
        if (words[i] == words[i - 1] + words[i].back()) {
            ret = words[i];
        }
        else break;
    }
    return ret;
}

int main() {
    vector<string> words{"d","do","dog","p","pe","pen","peng","pengu","pengui","penguin","e","el","ele","elep","eleph","elepha","elephan","elephant"};
    cout << longestWord(words) << endl;
    return 0;
}
