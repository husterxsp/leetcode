参考：discuss


https://leetcode.com/problems/k-th-smallest-prime-fraction/discuss/115486/Java-AC-O(max(nk)-*-logn)-Short-Easy-PriorityQueue

TLE
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n = A.size();

        auto cmp = [A](pair<int, int>const & a,  pair<int, int>const & b) {
            return A[a.first] * A[b.second] > A[a.second] * A[b.first];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n - 1; i++) pq.push({i, n - 1});

        while (K-- > 1) {
            pair<int, int> tmp = pq.top();
            pq.pop();

            if (tmp.second - 1 > tmp.first) pq.push({tmp.first, tmp.second - 1});
        }

        return vector<int>{A[pq.top().first], A[pq.top().second]};
    }
};
