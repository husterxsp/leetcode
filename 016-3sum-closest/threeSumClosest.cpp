#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cmp ( const void *a , const void *b){
    return *(int *)a - *(int *)b;
}
int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    
    int result=0, i, start, end, flag=0, sum;
    for (i = 0; i < numsSize-2; i++) {
        start = i + 1;
        end = numsSize - 1;
        while (start < end) {
            sum = nums[i] + nums[start] + nums[end];
            if (flag == 0) {
                result = sum;
                flag = 1;
            } else if (target == sum) {
                return sum;
            } else if (abs(target - sum) < abs(target - result)) {
                result = sum;
            }
            if (sum > target) {
                end--;
            } else {
                start++;
            }
        }
    }
    return result;
}

int main(){
    int nums[5] = {-4, -1, 1, 2};
    printf("%d", threeSumClosest(nums, 4, 1));
    return 0;
}