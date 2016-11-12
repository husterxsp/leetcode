#include <iostream>
#include <vector>
using namespace std;

// 位向量法(参考算法竞赛入门经典----子集生成)
void getSubsets(vector<vector<int>> &ret, vector<int>& check, vector<int>& nums, int cur){
    if(cur == nums.size()){
        vector<int> tmp;
        for(int i=0;i<cur;i++){
            if(check[i]){
                tmp.push_back(nums[i]);
            }
        }
        ret.push_back(tmp);
        return;
    }
    check[cur]=0;
    getSubsets(ret, check, nums, cur+1);
    check[cur]=1;
    getSubsets(ret, check, nums, cur+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> check(nums.size(), 0);
    getSubsets(ret, check, nums, 0);
    return ret;
}

int main()
{
    vector<int> a = {2,3};
    cout << subsets(a).size();
    return 0;
}