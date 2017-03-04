#include <iostream>
#include <vector>
#include <string>
using namespace std;

void find(vector<vector<string>> &allSol, vector<string> &sol, string &s, int start, vector<vector<bool>> &isPartion) {
    if (start == s.length()) {
        allSol.push_back(sol);
    }
    for (int i = start; i < s.length(); i++) {
        if (isPartion[start][i]) {
            sol.push_back(s.substr(start, i - start + 1));
            find(allSol, sol, s, i + 1, isPartion);
            sol.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> allSol;
    vector<string> sol;
    int n = s.length();
    if (n <= 0) return allSol;
    vector<vector<bool>> isPartion(n, vector<bool>(n, false));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if ((i + 1 > j - 1 || isPartion[i + 1][j - 1]) && s[i] == s[j])
                isPartion[i][j] = true;
        }
    }
    find(allSol, sol, s, 0, isPartion);
    return allSol;
}

int main() {
    partition("12332");
    return 0;
}
