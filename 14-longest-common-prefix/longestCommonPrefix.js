/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
    var result = '',
        i = 0;
    if (strs.length === 0) {
        return '';
    }
    if (strs.length === 1) {
        return strs[0];
    }
    while (i < strs[0].length && i < strs[1].length) {
        if (strs[0][i] === strs[1][i]) {
            result = strs[0].substring(0, i + 1);
            i++;
        } else {
            break;
        }
    }
    for (var j = 2; j < strs.length; j++) {
        for (var k = 0; k < i; k++) {
            if (result[k] !== strs[j][k]) {
                i = k;
                result = result.substring(0, i);
                break;
            }
        }
    }
    return result;
};

console.log(longestCommonPrefix(["abab", "aba", "abc"]));
