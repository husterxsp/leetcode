#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    if(height.size() <= 2){
        return 0;
    }
    int maxHeight=0, res=0;
    int *container = new int[height.size()];
    for(int i=0;i<height.size();i++){
        container[i] = maxHeight;
        maxHeight = max(maxHeight, height[i]);
    }
    maxHeight = 0;
    for(int i=height.size()-1;i>=0;i--){
        container[i] = min(container[i], maxHeight);
        res += container[i]-height[i]>0?container[i]-height[i]:0;
        maxHeight = max(maxHeight, height[i]);
    }
    return res;
}

int main() {
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    cout << trap(nums);
    return 0;
}