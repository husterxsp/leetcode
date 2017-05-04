### 1. Two Sum

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.
The return format had been changed to zero-based indices.

Example:

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```

Tags:
1. Array
2. Hash Table
Similar Problems:
1. (M) 3Sum
2. (M) 4Sum (E) Two Sum II - Input array is sorted
3. (E) Two Sum III - Data structure design

解法思路：
1. map
2. 先排序，再二分查找
