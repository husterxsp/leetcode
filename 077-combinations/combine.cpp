#include <iostream>
#include <vector>
using namespace std;
// Input:
// 4
// 3
// Output:
// [[1,2,3],[1,3,4],[2,3,4]]
// Expected:
// [[1,2,3],[1,2,4],[1,3,4],[2,3,4]]
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> nums(n+1,0);
    if(k <= 0) {
        return ret;
    }
    for(int i=1;i<=n;i++){
        nums[i] = i;
    }
    for(int i=1;i<=n-k+1;i++){
        if(k == 1){
            vector<int> tmp;
            tmp.push_back(i);
            ret.push_back(tmp);
        } else {
            for(int j=i;j<=n-k+1;j++){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.insert(tmp.begin()+1, nums.begin()+j+1, nums.begin()+j+k);
                ret.push_back(tmp);
            }
        }
    }
    return ret;
}

int main(){
    combine(4, 1);
    return 0;
}
