#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ret;

// 解法一：直接使用标准库函数，可以AC
vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    do
    {
        ret.push_back(nums);
    }while(next_permutation(nums.begin(), nums.end()));
    return ret;
}

// 解法二, 直接遍历。参考算法竞赛入门经典书中---生成可重集的排序
void getPermuteUnique(vector<vector<int>> &ret, vector<int> &used, vector<int>& nums, int cur){
    int n = nums.size();
    if(cur == n){
        vector<int> tmp;
        for(int i=0;i<n;i++){
            tmp.push_back(used[i]);
        }
        ret.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        if(!i || nums[i]!=nums[i-1]){
            int c1=0, c2=0;
            for(int j=0;j<cur;j++)if(used[j]==nums[i])c1++;
            for(int j=0;j<n;j++)if(nums[j]==nums[i])c2++;
            if(c1<c2){
                used[cur] = nums[i];
                getPermuteUnique(ret, used, nums, cur+1);
            }
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ret;
    vector<int> used(n, 0);
    sort(nums.begin(), nums.end());
    getPermuteUnique(ret, used, nums, 0);
    return ret;
}

int main(){
    vector<int> arr(3, 0);
    for(int i=0;i<3;i++){
        cin >> arr[i];
    }
    permuteUnique(arr);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
