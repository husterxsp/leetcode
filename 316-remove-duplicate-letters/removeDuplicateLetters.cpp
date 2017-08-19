// 错解，例如："xvxcvcx"
// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         string ret = "";
//         unordered_map<char> myMap;
//         int n = s.size();
//         for (char c : s) {
//             if (myMap.find(c) == mySet.end()) ret += c;
//             else {
//                 int index = myMap[c];
//                 if (s[index] > index[index + 1]) {
//                     s.erase(s.begin() + index);
//                     s += c;
//                 }
//             }
//         }
//         return ret;
//     }
// };

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ret = "0";
        unordered_map<char, int> remain, existed;

        for (auto c : s) remain[c]++;
        for (auto c : s) {
            remain[c]--;
            if (existed[c]) continue;
            while (c < ret.back() && remain[ret.back()]) {
                existed[ret.back()] = 0;
                ret.pop_back();
            }
            ret += c;
            existed[c] = 1;
        }
        return ret.substr(1);
    }
};
