easy ? sort的compare函数如何传入参数

class Solution {
public:
    string customSortString(string S, string T) {
        map<char, int> m;
        for (int i = 0; i < S.size(); i++) m[S[i]] = i;

        for (int i = 0; i < T.size(); i++) {
            if (m.find(T[i]) == m.end()) {
                m[T[i]] == INT_MAX;
            }
        }

        sort(T.begin(), T.end(), [&](const char a, const char b) {
            return m[a] < m[b];
        });

        return T;
    }
};
