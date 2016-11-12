/**
 * @param {number} x
 * @return {boolean}
 */

var isPalindrome = function (x) {
    var reverse = function (x) {
        var tmp = x < 0 ? -x : x;
        tmp = parseInt(tmp.toString().split('').reverse().join(''));
        tmp = x < 0 ? -tmp : tmp;
        return tmp;
    };
    if (x === reverse(x)) {
        return true;
    } else {
        return false;
    }
};
