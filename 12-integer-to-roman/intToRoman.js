/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
    var nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    var romans = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    var i = 0;
    var result = [];
    while (num > 0) {
        var times = num / nums[i];
        if (times >= 1) {
            num %= nums[i];
            while (times-- >= 1) {
                result.push(romans[i]);
            }
        }
        i++;
    }
    return result.join('');
};

console.log(intToRoman(6));
