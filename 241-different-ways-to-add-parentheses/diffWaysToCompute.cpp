#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <math.h>

using namespace std;
// 解法1
// vector<int> diffWaysToCompute(string input) {
//     vector<int> output;
//     for (int i = 0; i < input.size(); i++) {
//         char c = input[i];
//         if (c == '+' || c == '*' || c == '-') {
//             vector<int> left = diffWaysToCompute(input.substr(0, i));
//             vector<int> right = diffWaysToCompute(input.substr(i + 1));
//             for (auto l : left) {
//                 for (auto r : right) {
//                     if (c == '+') {
//                         output.push_back(l + r);
//                     }
//                     else if (c == '*') {
//                         output.push_back(l * r);
//                     }
//                     else {
//                         output.push_back(l - r);
//                     }
//                 }
//             }
//         }
//     }
//     if (output.empty()) {
//         output.push_back(stoi(input));
//     }
//     return output;
// }

// 解法2
unordered_map<string, vector<int>> cache;
vector<int> diffCompute(string input, int start, int end) {
    string key = to_string(start) + "-" + to_string(end);
    if (cache.find(key) != cache.end()) {
        cout << key << endl;
        return cache[key];
    }

    vector<int> output;

    for (int i = start; i < end; i++) {
        char c = input[i];
        if (c == '+' || c == '-' || c == '*') {
            vector<int> left = diffCompute(input, start, i - 1);
            vector<int> right = diffCompute(input, i + 1, end);
            for (auto l : left) {
                for (auto r : right) {
                    if (c == '+') {
                        output.push_back(l + r);
                    }
                    else if (c == '-') {
                        output.push_back(l - r);
                    }
                    else {
                        output.push_back(l * r);
                    }
                }
            }
        }
    }

    if (output.empty()) {
        output.push_back(stoi(input.substr(start, end - start + 1)));
    }
    else {
        cache[key] = output;
    }
    return output;
}

int main () {
    cout << diffWaysToCompute("2*3-4*5") << endl;
    return 0;
}
