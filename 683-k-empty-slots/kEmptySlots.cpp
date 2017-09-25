class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        int n = flowers.size();
        unordered_set<int> mySet{flowers[0]};

        for (int i = 1; i < n; i++) {
            mySet.insert(flowers[i]);
            if (mySet.find(flowers[i] - k - 1) != mySet.end()) {
                int j = 0;
                while (j < i) {
                    if (flowers[j] > flowers[i] - k - 1 && flowers[j] < flowers[i]) break;
                    j++;
                }
                if (j == i) return i + 1;
            }
            if (mySet.find(flowers[i] + k + 1) != mySet.end()) {
                int j = 0;
                while (j < i) {
                    if (flowers[j] > flowers[i] && flowers[j] < flowers[i] + k + 1) break;
                    j++;
                }
                if (j == i) return i + 1;
            }

        }
        return -1;
    }
};
