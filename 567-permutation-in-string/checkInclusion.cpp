class Solution {
public:
    /**
        思路：双指针
    */
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        if (l1 > l2 || l2 == 0) return false;

        unordered_map<char, int> m1, m2;
        for (int i = 0; i < l1; i++) {
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        unordered_set<char> mySet;
        for (auto it : m1) {
            if (it.second != m2[it.first]) mySet.insert(it.first);
        }
        for (int i = l1; i < l2; i++) {
            if (mySet.empty()) return true;
            m2[s2[i]]++;
            m2[s2[i - l1]]--;

            if (m1[s2[i]] == m2[s2[i]]) mySet.erase(s2[i]);
            else mySet.insert(s2[i]);

            if (m1[s2[i - l1]] == m2[s2[i - l1]]) mySet.erase(s2[i - l1]);
            else mySet.insert(s2[i - l1]);
        }
        if (mySet.empty()) return true;
        return false;
    }
};
