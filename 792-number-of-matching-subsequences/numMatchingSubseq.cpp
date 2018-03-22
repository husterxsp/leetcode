//  Memory Limit Exceeded  && Time Limit Exceeded
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ret = 0;
        vector<map<char, int>> vec(S.size());

        map<char, int> curMap;
        for (int i = 0; i < 26; i++) curMap['a' + i] = -1;
        curMap[S.back()] = S.size() - 1;
        vec[S.size() - 1] = curMap;

        for (int i = S.size() - 2; i >= 0; i--) {
            curMap[S[i]] = i;
            vec[i] = curMap;
        }

        for (int i = 0; i < words.size(); i++) {
            string w = words[i];

            int pos = 0, j = 0;
            for (j = 0; j < w.size(); j++) {
                char c = w[j];
                if (pos >= S.size() || vec[pos][c] == -1) break;
                else {
                    pos = vec[pos][c] + 1;
                }
            }
            if (j == w.size()) ret++;
        }
        return ret;
    }
};

参考 discuss
#include <bits/stdc++.h>

using namespace std;

//int numMatchingSubseq(string S, vector<string>& words) {
//    int ret = 0;
//    vector<map<char, int>> vec(S.size());
//
//    map<char, int> curMap;
//    for (int i = 0; i < 26; i++) curMap['a' + i] = -1;
//    curMap[S.back()] = S.size() - 1;
//    vec[S.size() - 1] = curMap;
//
//    for (int i = S.size() - 2; i >= 0; i--) {
//        curMap[S[i]] = i;
//        vec[i] = curMap;
//    }
//
//    for (int i = 0; i < words.size(); i++) {
//        string w = words[i];
//
//        int pos = 0, j = 0;
//        for (j = 0; j < w.size(); j++) {
//            char c = w[j];
//            if (pos >= S.size() || vec[pos][c] == -1) break;
//            else {
//                pos = vec[pos][c] + 1;
//            }
//        }
//        if (j == w.size()) ret++;
//    }
//    return ret;
//}

int numMatchingSubseq(string S, vector<string>& words) {
    vector<pair<int, int>> waiting[128];
    for (int i = 0; i < words.size(); i++)
        waiting[words[i][0]].emplace_back(i, 1);
    for (char c : S) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[words[it.first][it.second++]].push_back(it);
    }
    return waiting[0].size();
}

int main() {

    vector<string> words{"hhwnxyzltiscrjztiivnpnzlubzpueihinsqdfvyp","vnpnzlubzpueihinsqdfvypdteztiodbha","rcnrcylxolxlnhhwnxyzltiscrjztiivnpnzlubzpueihi","dfvypdteztiodbhaqhxskupwulvk","zltiscrjztii","wdmbatbcewwittubryrqwwrvfkrmniomofygybeqfzusrgeart","myzfexqmzxnbmmnhmpbddqhrwrobqzjiwdzzpyzodejysuuquc","wxvrcbihbasohfvuwuxleesqeujxvjfvgwnhltenbspdgzsdrs","nztyysfhfbfcihyeaqdarqxfpjunevabzafvbmpbtenarvyizv","nivufheyodfjuggrbndyojeahrzgptikjfqufhwyhzyyjteahx"};
    numMatchingSubseq("iwdlcxpyagegrcnrcylxolxlnhhwnxyzltiscrjztiivnpnzlubzpueihinsqdfvypdteztiodbhaqhxskupwulvkzhczdyoouym", words);
    return 0;
}
