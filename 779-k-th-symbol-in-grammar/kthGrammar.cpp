// 超时
// class Solution {
// public:
//     int kthGrammar(int N, int K) {
//         vector<string> arr{"0"};
//         for (int i = 1; i < N; i++) {
//             string tmp = "";
//             for (int j = 0; j < arr[i - 1].size(); j++) {
//                 tmp += arr[i - 1][j] == '0' ? "01" : "10";
//             }
//             arr.push_back(tmp);
//         }
//         return arr[N - 1][K - 1] - '0';
//     }
// };

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        if (K <= pow(2, N - 2)) return kthGrammar(N - 1, K);
        return kthGrammar(N - 1, K - pow(2, N - 2)) == 0 ? 1 : 0;
    }
};
