/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
    var tmp = x < 0 ? -x : x;
    tmp = parseInt(tmp.toString().split('').reverse().join(''));
    tmp = x < 0 ? -tmp : tmp;
    return tmp;
};
console.log(reverse(10100));
