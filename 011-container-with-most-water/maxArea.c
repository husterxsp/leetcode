#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxArea(int *height, int heightSize){
    int result = 0, i = 0, j = heightSize-1;
    while(i<j){
        int tmp = height[i]<height[j]? height[i]:height[j];
        int area = tmp*(j-i);
        if(area > result){
            result = area;
        }
        height[i] < height[j] ? i++ : j--;
    }
    return result;
}

int main() {
    int height[] = {1,2,4,3};
//    printf("%lu", sizeof(height)/sizeof(height[0]));
    printf("%d\n", maxArea(height, sizeof(height)/sizeof(height[0])));
    return 0;
}
