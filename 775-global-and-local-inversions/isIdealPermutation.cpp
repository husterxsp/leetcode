// 超时
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        set<int> mySet;
        for (int i = 0; i < n - 1; i++) {
            mySet.insert(A[i]);

            int dis = distance(mySet.begin(), mySet.find(A[i]));

            if (dis == A[i] - 1 && A[i] > A[i + q]) continue;
            else return false;
        }
        return true;
    }
};

/**
    I could only place i at A[i-1],A[i] or A[i+1]. So it came up to me, It will be easier just to check if all A[i] - i equals to -1, 0 or 1.
    Take 0, 1, 2, 3, 4, 5, 6, 7, 8 as an example, imaging where you would place 3. You can actually place it at one of [2], [3], [4].
    Proof by contradiction:
    If we placed it at index 0..1, then one of 0..2 would have to be in the index of 3..5, we call it x. And we also know that max[1] is 3, that means we know for sure that we have a global inversion: 3 is in index 0..1, x = 0..2 is in index 3..5, and 3 > x, their distance is at least 2.
    If we place 3 at index 5..8, then there must exist one x in the range of 4..8 such that it's placed now in 0..3. By an analysis similar to the one above, we know that x = 4..8 is in index 0..3, and 3 is in index 5..8. There has to be an at-least-distance-2 inversion.
*/
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            if (abs(A[i] - i) > 1) return false;
        }
        return true;
    }
};
