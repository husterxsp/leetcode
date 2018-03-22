class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        int len = A.size();
        multimap<int , int> aMap, bMap;

        for (int i = 0; i < len; i++) {
            aMap.insert({A[i], i});
            bMap.insert({B[i], i});
        }
        vector<int> ret(len);

        set<int> ele(A.begin(), A.end());
        for (auto n : ele) {
            auto rangeA = aMap.equal_range(n);
            auto rangeB = bMap.equal_range(n);

            auto itA = rangeA.first, itB = rangeB.first;
            while (itA != rangeA.second) {
                ret[itA->second] = itB->second;

                itA++;
                itB++;
            }
        }
        return ret;
    }

};
