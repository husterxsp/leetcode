// 错解，错误地理解题目中“子串”的意思
// class Solution {
// public:
//     int findLUSlength(string a, string b) {
//         if (a.compare(b) == 0) return -1;
//         if (a.size() < b.size()) swap(a, b);
//
//         int ret = 0;
//         for (int i = 0; i < a.size(); i++) {
//             for (int j = i; j < a.size(); j++) {
//                 string str = a.substr(i, j - i + 1);
//                 if (b.find(str) == string::npos) {
//                     ret = max(ret, (int)str.size());
//                 }
//             }
//         }
//         return ret;
//     }
// };
/*
    0ms的解答。。真是服气
*/
class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a == b) return -1;
        if (a.length() > b.length()) return a.length();
        return b.length();
    }
};
