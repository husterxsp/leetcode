/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
    var generate = function (left, right, parenthesis, result) {
        if (left === 0 && right === 0) {
            result.push(parenthesis);
            return;
        }
        if (left > 0) {
            generate(left - 1, right, parenthesis + '(', result);
        }
        if (right > 0 && right > left) {
            generate(left, right - 1, parenthesis + ')', result);
        }
    };

    if (n <= 0) {
        return [];
    }
    var result = [];
    generate(n, n, '', result);
    return result;
};
console.log(generateParenthesis(3));
