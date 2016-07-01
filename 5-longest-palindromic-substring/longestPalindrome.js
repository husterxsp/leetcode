/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome1 = function (s) {
    var start,
        end,
        center,
        length = s.length,
        result = '';
    if (length == 1) {
        return s;
    }
    for (center = 1; center < length; center++) {
        //奇数
        start = center - 1;
        end = center + 1;
        while (start >= 0 && end < length && s[start] == s[end]) {
            start--;
            end++;
        }
        if (result.length < s.substring(start + 1, end).length) {
            result = s.substring(start + 1, end);
        }
        //偶数
        start = center - 1;
        end = center;
        while (start >= 0 && end < length && s[start] == s[end]) {
            start--;
            end++;
        }
        if (result.length < s.substring(start + 1, end).length) {
            result = s.substring(start + 1, end);
        }
    }
    return result;
};

// Manacher算法
var longestPalindrome2 = function () {

};

console.log(longestPalindrome('aq'));
