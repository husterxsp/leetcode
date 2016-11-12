#include <iostream>
#include <vector>

using namespace std;

// 此题类似于第97题
// 1. wrong answer   "", "*"
// 2. Memory Limit Exceeded, match mn 数组太大了
//
// bool isMatch(string s, string p) {
//     int m = s.length(), n = p.length();
//     vector<vector<int>> match(m + 5, vector<int>(n + 5, 0));
//     match[0][0] = 1;
//
//     for (int i = 1; i <= n; i++) {
//         if (p[i - 1] == '*') {
//             match[0][i] = 1;
//         }
//         else {
//             break;
//         }
//     }
//
//     for (int i = 1; i <= m; i++) {
//         for (int j = 1; j <= n; j++) {
//             if (p[j-1] == '?' || s[i-1] == p[j-1]) {
//                 match[i][j] = match[i - 1][j - 1];
//             }
//             else if (p[j-1] == '*') {
//                 if (match[i - 1][j] || match[i][j - 1] || match[i-1][j-1]) {
//                     match[i][j] = 1;
//                 }
//             }
//             else {
//                 match[i][j] = 0;
//             }
//         }
//     }
//
//     for (int i = 0; i <= m ; i++) {
//         for (int j = 0; j <= n; j++) {
//             cout << match[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     return match[m][n];
// }

// 缩小match数组为二维，AC
bool isMatch(string s, string p) {
    int m = s.length(), n = p.length();
    vector<vector<int>> match(2, vector<int>(n + 1, 0));
    match[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            match[0][i] = 1;
        }
        else {
            break;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '?' || s[i-1] == p[j-1]) {
                match[1][j] = match[0][j - 1];
            }
            else if (p[j-1] == '*') {
                if (match[0][j] || match[1][j - 1] || match[0][j-1]) {
                    match[1][j] = 1;
                }
            }
            else {
                match[1][0] = 0;
            }
        }
        for (int k = 0; k <= n; k++) {
            match[0][k] = match[1][k];
            match[1][k] = 0;
        }
    }
    return match[0][n];
}

int main () {
    cout << isMatch("cab", "c*a*b");
    return 0;
}
