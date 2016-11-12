#include <iostream>
#include <vector>
using namespace std;

//第一感觉就是个排序
//但是没想到空间利用的问题，题目中给出了计数排序，但是需要两遍遍历
//问还有没有更优解
//虽然想到了交换，但是没想太仔细。。
//0，1，2，这是相当于两个指针移动。那如果数再多，是不是就加指针。
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void sortColors(vector<int>& nums) {
    int left=0, right=nums.size()-1, i=0;
    while (i<=right) {
        if(nums[i]==0){
            swap(&nums[i++], &nums[left++]);
        }else if(nums[i]==1){
            i++;
        }else {
            swap(&nums[i], &nums[right--]);
        }
    }
}

int main(){
    vector<int> a = {1,1,1,0,0,0,2,0};
    sortColors(a);
    return 0;
}