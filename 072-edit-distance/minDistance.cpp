#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int len1 = word1.length(), len2 = word2.length();
    vector<vector<int>> arr(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; i++) arr[i][0] = i;
    for (int j = 0; j <= len2; j++) arr[0][j] = j;
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                arr[i][j] = arr[i - 1][j - 1];
            }
            else {
                arr[i][j] = min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]) + 1;
            }
        }
    }
    return arr[len1][len2];
}

int main() {
    cout << minDistance(" ", "abc") << endl;
    return 0;
}
