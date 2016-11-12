/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
    var obj = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };
    var result = 0,
        length = s.length;
    for (var i = 0; i < length; i++) {
        if (obj[s[i]] >= obj[s[i + 1]] || i == length - 1) {
            result += obj[s[i]];
        } else {
            result -= obj[s[i]];
        }
    }
    return result;
};
console.log(romanToInt('DCXXI'));
