/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
    var nums = digits.split('');
    var obj = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };
    if (nums.length === 0) {
        return [];
    }
    if (nums.length === 1) {
        return obj[nums[0]];
    }
    var result = obj[nums[0]];
    for (var i = 1; i < digits.length; i++) {
        var tmp1 = obj[nums[i]];
        var tmp2 = [];
        for (var j = 0; j < result.length; j++) {
            for (var k = 0; k < tmp1.length; k++) {
                tmp2.push(result[j] + tmp1[k]);
            }
        }
        result = tmp2;
    }
    return result;
};

console.log(letterCombinations('234'));
