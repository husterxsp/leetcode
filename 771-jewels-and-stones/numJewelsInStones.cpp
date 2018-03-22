class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char, int> myMap;
        set<char> mySet(J.begin(), J.end());

        for (char c : S) myMap[c]++;

        int ret = 0;
        for (char c : mySet) ret += myMap[c];

        return ret;
    }
};
