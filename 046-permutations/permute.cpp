#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ret;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void perm(vector<int>& nums, int begin, int end){
    if(begin == end){
        ret.push_back(nums);
        return;
    }
    for(int i=begin;i<=end;i++){
        swap(&nums[begin], &nums[i]);
        perm(nums, begin+1, end);
        swap(&nums[begin], &nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    perm(nums, 0, (int)nums.size()-1);
    return ret;
}

int main(){
    vector<int> arr(3, 0);
    for(int i=0;i<3;i++){
        cin >> arr[i];
    }
    permute(arr);
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++){
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
