int firstMissingPositive(vector<int>& nums) {
    int res = 1;
    sort(nums.begin(), nums.end());
    for(int i=0;i<nums.size();i++){
        if(nums[i] <= 0){
            continue;
        }
        // 注意重复序列
        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }
        if(nums[i] == res){
            res++;
        } else {
            return res;
        }   
    }
    return res;
}