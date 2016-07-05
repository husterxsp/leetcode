/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum1 = function (nums) {
    var result = [];
    var sign = 0;
    nums.sort((value1, value2) => value1 - value2);
    for (var i = 0; i < nums.length; i++) {
        if (nums[i] == nums[i - 1]) {
            continue;
        }
        var two = twoSum(nums.slice(i + 1), -nums[i]);
        for (var j = 0; j < two.length; j++) {
            two[j].unshift(nums[i]);
        }
        result = result.concat(two);
    }

    result = result.map(item => item.toString());
    result = Array.from(new Set(result));
    result = result.map(item => item.split(',').map(item => +item));
    return result;

    function twoSum(nums, num) {
        var result = [];
        for (var i = 0; i < nums.length; i++) {
            var one = binarySearch(nums.slice(i + 1), num - nums[i]);
            if (one !== undefined) {
                //这里需去重
                result.push([nums[i], one]);
            }
        }
        return result;
    }

    function binarySearch(nums, num) {
        var start = 0,
            end = nums.length - 1,
            mid;
        while (start <= end) {
            mid = Math.floor((start + end) / 2);
            if (num < nums[mid]) {
                end = mid - 1;
            } else if (num > nums[mid]) {
                start = mid + 1;
            } else if (num == nums[mid]) {
                return nums[mid];
            } else {
                return;
            }
        }
        return;
    }
};
var threeSum2 = function (nums) {

};
console.log(threeSum([0, 0, 0, 0]));
