#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> majorityElement(vector<int>& nums) {
    int candidateNum = 2;
    int candidateSize = nums.size() / 3;
    vector<int> candidate(candidateNum);
    vector<int> count(candidateNum, 0);

    // candidate 初始化。。这个地方得注意啊啊啊。
    // 注意这个数组不能初始化为一样的数，否则这样的输入就会有问题 {1,1,1}
    // 默认是都初始化为0了
    for (int i = 0; i < candidate.size(); i++) {
        candidate[i] = i;
    }
    //-----------

    for (auto n : nums) {
        int i = 0;
        for (i = 0; i < candidateNum; i++) {
            if (n == candidate[i]) {
                count[i]++;
                break;
            }
        }

        if (i < candidateNum) continue;

        for (i = 0; i < candidateNum; i++) {
            if (count[i] == 0) {
                count[i]++;
                candidate[i] = n;
                break;
            }
        }

        if (i < candidateNum) continue;

        for (i = 0; i < candidateNum; i++) {
            count[i]--;
        }
    }
    vector<int> num(candidateNum, 0);
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < candidate.size(); j++) {
            if (nums[i] == candidate[j]) {
                num[j]++;
            }
        }
    }
    for (int i = 0; i < candidate.size(); i++) {
        if (num[i] <= candidateSize) {
            candidate.erase(candidate.begin() + i);
            num.erase(num.begin() + i);
            i--;
        }
    }
    return candidate;
}

int main () {
    vector<int> arr = {1,1,2,2,2,8,8,8};
    majorityElement(arr);
    return 0;
}
