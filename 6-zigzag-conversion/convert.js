/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */

//找规律
var convert1 = function (s, numRows) {
    var col;
    var result = [];
    var length = s.length;
    if (s.length === 1 || numRows === 1) {
        return s;
    }
    for (var i = 0; i < numRows; i++) {
        col = 0;
        if (i === 0 || i === numRows - 1) {
            while (i + 2 * col * (numRows - 1) < length) {
                result.push(s[i + 2 * col * (numRows - 1)]);
                col++;
            }
        } else {
            while (i + 2 * col * (numRows - 1) < length) {
                result.push(s[i + 2 * col * (numRows - 1)]);
                if (2 * (col + 1) * (numRows - 1) - i < length) {
                    result.push(s[2 * (col + 1) * (numRows - 1) - i]);
                }
                col++;
            }
        }
    }
    return result.join('');
};

var convert2 = function (s, numRows) {
    var col;
    var result = [];
    var length = s.length;
    if (s.length === 1 || numRows === 1) {
        return s;
    }
    for (var i = 0; i < numRows; i++) {
        for (var j = i; j < length; j += 2 * (numRows - 1)) {
            result.push(s[j]);
            if (i > 0 && i < numRows - 1 && (j + 2 * (numRows - i - 1)) < length) {
                result.push(s[j + 2 * (numRows - i - 1)]);
            }
        }
    }
    return result.join('');
}
console.log(convert2('A', 1));
