/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function (nums, target) {
    nums.sort((value1, value2) => value1 - value2);
    var result = [];
    for (var i = 0; i < nums.length - 3; i++) {
        if (nums[i] === nums[i - 1]) {
            continue;
        }
        for (var j = i + 1; j < nums.length - 2; j++) {
            if (j !== i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            var start = j + 1;
            var end = nums.length - 1;
            while (start < end) {
                var sum = nums[i] + nums[j] + nums[start] + nums[end];
                if (sum === target) {
                    result.push([nums[i], nums[j], nums[start], nums[end]]);
                    start++;
                    end--;
                    while (nums[start] === nums[start - 1]) {
                        start++;
                    }
                    while (nums[end] === nums[end + 1]) {
                        end--;
                    }
                } else if (sum > target) {
                    end--;
                } else if (sum < target) {
                    start++;
                }
            }
        }
    }
    return result;
};

console.log(fourSum([1, 0, -1, 0, -2, 2], 0));
