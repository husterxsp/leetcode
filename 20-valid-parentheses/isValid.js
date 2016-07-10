/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    var stack = [];
    for (var i = 0; i < s.length; i++) {
        var value = s.charAt(i);
        if (value == '(' || value == '{' || value == '[') {
            stack.push(value);
        } else {
            var left = stack.pop();
            var right = s.charAt(i);
            if (!((left == '(' && right == ')') || (left == '{' && right == '}') || (left == '[' && right == ']'))) {
                return false;
            }
        }
    }
    if (stack.length === 0) {
        return true;
    } else {
        return false;
    }
};
console.log(isValid('[()]'));
