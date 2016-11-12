/**
 * @param {string} s
 * @return {number}
 */

//js 内置方法的执行效率？内置方法的实现？
var lengthOfLongestSubstring1 = function (s) {
    var prevStr = '';
    var currStr = '';
    var strLen = s.length;
    for (var i = 0; i < strLen; i++) {
        currStr = s.substring(i, i + 1);
        for (var j = i + 1; j < strLen; j++) {
            var currChar = s.charAt(j);
            if (currStr.indexOf(currChar) === -1) {
                currStr = s.substring(i, j + 1);
            } else {
                break;
            }
        }
        if (currStr.length > prevStr.length) {
            prevStr = currStr;
        }
    }
    return prevStr.length;
};

//改进
var lengthOfLongestSubstring2 = function (s) {
    var prevStr = '';
    var currStr = '';
    var strLen = s.length;
    for (var i = 0; i < strLen; i++) {
        currStr = s.substring(i, i + 1);
        for (var j = i + 1; j < strLen; j++) {
            var currChar = s.charAt(j);
            if (currStr.indexOf(currChar) === -1) {
                currStr = s.substring(i, j + 1);
            } else {
                if (i < currStr.indexOf(currChar)) {
                    i = currStr.indexOf(currChar);
                }
                break;
            }
        }
        if (currStr.length > prevStr.length) {
            prevStr = currStr;
        }
    }
    return prevStr.length;
};

//leetcode解法, Set
var lengthOfLongestSubstring3 = function (s) {
    var strLen = s.length;
    var set = new Set();
    var length = 0;
    var i = 0;
    var j = 0;
    while (i < strLen && j < strLen) {
        if (!set.has(s.charAt(j))) {
            set.add(s.charAt(j++));
            length = Math.max(length, j - i);
        } else {
            set.delete(s.charAt(i++));
        }
    }
    return length;
};

//leetcode解法, Map
var lengthOfLongestSubstring4 = function (s) {
    var strLen = s.length;
    var map = new Map();
    var length = 0;
    var i = 0;
    var j = 0;
    for (; j < strLen; j++) {
        if (map.has(s.charAt(j))) {
            i = Math.max(map.get(s.charAt(j)), i);
        }
        length = Math.max(length, j - i + 1);
        map.set(s.charAt(j), j + 1);
    }
    return length;
}

console.log(lengthOfLongestSubstring4('abcdefc'));
