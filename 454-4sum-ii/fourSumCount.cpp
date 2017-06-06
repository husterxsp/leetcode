/**
    注意题中给的条件啊，same length
    解题思路：对四个数组两两求和，复杂度降至O(n^2)
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        unordered_map<int, int> m1, m2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m1[A[i] + B[j]]++;
                m2[C[i] + D[j]]++;
            }
        }
        int ret = 0;
        for (auto itor : m1) {
            ret += itor.second * m2[-itor.first];
        }
        return ret;
    }
};
