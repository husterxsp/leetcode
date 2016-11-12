/**
 * @param {number[]} height
 * @return {number}
 */

var maxArea = function (height) {
    var result = 0,
        length = height.length,
        i = 0,
        j = length - 1;
    while (i < j) {
        var area = (j - i) * Math.min(height[i], height[j]);
        if (area > result) {
            result = area;
        }
        height[i] < height[j] ? i++ : j--;
    }
    return result;
}
console.log(maxArea([1, 2, 4, 3]));
