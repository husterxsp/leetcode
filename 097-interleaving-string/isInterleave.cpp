#include <iostream>
#include <vector>
#include <Map>
using namespace std;

// 回溯，递归超时。。
// 1.Wrong: "a", "b", "a"
// 2.Time Limit Exceeded: "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa"
// "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab"
//"babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab"
// bool interleave(string s1, string s2, string s3, bool isS1) {
//     if (!s3.length() && !s1.length() && !s2.length()) {
//         return true;
//     }
//     if (s1.length() + s2.length() != s3.length()) {
//         return false;
//     }
//     string s = "";
//     if (isS1) {
//         s = s1;
//     } else {
//         s = s2;
//     }
//     int len = 1;
//     string str = "";
//     while (len <= s3.length() && len <= s.length()) {
//         if (s3.substr(0, len).compare(s.substr(0, len)) == 0 ) {
//             if ( (isS1 && interleave(s1.substr(len), s2, s3.substr(len), !isS1)) ||
//                 (!isS1 && interleave(s1, s2.substr(len), s3.substr(len), !isS1)) ) {
//                 return true;
//             } else {
//                 len++;
//             }
//         } else {
//             break;
//         }
//     }
//     return false;
// }
// bool isInterleave(string s1, string s2, string s3) {
//     return interleave(s1, s2, s3, 0) || interleave(s1, s2, s3, 1);
// }

// 还是只能用动规
// "aabcc", "dbbca", "aadbbcbcac"
// match 数组：
// 1 0 0 0 0 0
// 1 0 0 0 0 0
// 1 1 1 1 1 0
// 0 1 1 0 1 0
// 0 0 1 1 1 1
// 0 0 0 1 0 1
bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3) return false;
    vector<vector<int>> match(l1 + 5, vector<int>(l2 + 5, 0));
    match[0][0] = 1;
    for (int i = 0; i < l1; i++) {
        if (s1[i] == s3[i]) {
            match[i + 1][0] = 1;
        }
        else {
            break;
        }
    }
    for (int i = 0; i < l2; i++) {
        if (s2[i] == s3[i]) {
            match[0][i + 1] = 1;
        }
        else {
            break;
        }
    }
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if ((s1[i - 1] == s3[i + j - 1] && match[i - 1][j])
                || (s2[j - 1] == s3[i + j - 1] && match[i][j - 1])) {
                match[i][j] = 1;
            }
            else {
                match[i][j] = 0;
            }
        }
    }
    return match[l1][l2];
}

int main() {
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}
