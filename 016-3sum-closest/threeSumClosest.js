/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function (nums, target) {
    var result;
    nums.sort((value1, value2) => value1 - value2);
    for (var i = 0; i < nums.length - 2; i++) {
        var start = i + 1;
        var end = nums.length - 1;
        while (start < end) {
            var sum = nums[i] + nums[start] + nums[end];
            if (result === undefined) {
                result = sum;
            } else if (target === sum) {
                return sum;
            } else if (Math.abs(target - sum) < Math.abs(target - result)) {
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
};
console.log(threeSumClosest([-1, 2, 1, -4], 1));
