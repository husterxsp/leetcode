#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxNum, thisNum, i;
    maxNum = -1000000;
    thisNum = 0;
    for(i=0;i<nums.size();i++){
        if(thisNum < 0 && nums[i] < 0){
            thisNum = nums[i];
        }else {
            thisNum += nums[i];
        }
        
        maxNum = max(thisNum, maxNum);
        thisNum = max(0, thisNum);
    }
    return maxNum;
}

int main(){
    int n;
    vector<int> in = {-2,-1};
    cout << maxSubArray(in);
    return 0;
}
