/**
 * @param {string} s
 * @param {string} p
 * @return {boolean}
 */
var isMatch1 = function (s, p) {
    p = new RegExp(p, 'g');
    var result = p.exec(s);
    if (result === null || result[0] !== s) {
        return false;
    } else {
        return true;
    }
};

// var isMatch2 = function (s, p) {
//     var pointerA = 0,
//         pointerB = 0;
//     while (pointerA < s.length) {
//         if (s[pointerA] === p[pointerB]) {
//             pointerA++;
//             pointerB++;
//         } else if (p[pointerB] === '.') {
//             if (p[pointerB + 1] === '*') {
//                 if (p[pointerB + 2] === undefined) {
//                     return true;
//                 } else {
//                     while (s[pointerA] !== p[pointerB + 2] && pointerA < s.length) {
//                         pointerA++;
//                     }
//                     if (s[pointerA] === p[pointerB + 2]) {
//                         pointerA++;
//                         pointerB += 3;
//                     } else {
//                         return false;
//                     }
//                 }
//             } else {
//                 pointerA++;
//                 pointerB++;
//             }
//         } else if (p[pointerB] === '*') {

//             while (s[pointerA] === p[pointerB - 1] && pointerA < s.length) {
//                 pointerA++;
//             }
//             pointerB++;
//             while (p[pointerB] === s[pointerA - 1]) {
//                 pointerB++;
//             }
//         } else if (p[pointerB + 1] === '*') {
//             pointerB += 2;

//         } else {
//             return false;
//         }
//     }
//     if (pointerB < p.length) {
//         return false;
//     }
//     return true;
// };
// console.log(isMatch2('aaa', 'ab*a*c*a'));


function isMatch(s, p) {
    var i = 0,
        j = 0;
    if (s.length === 0) {
        if (p.length % 2 !== 0) {
            return false;
        }
        for (var k = 1; k < p.length; k += 2) {
            if (p[k] != '*') {
                return false;
            }
        }
        return true;
    }
    if (p[j + 1] == '*') {
        if (s[i] == p[j] || p[j] == '.') {
            return isMatch(s.substring(1), p) || isMatch(s, p.substring(2));
        } else {
            return isMatch(s, p.substring(2));
        }
    } else {
        if (s[i] == p[j] || p[j] == '.') {
            return isMatch(s.substring(1), p.substring(1));
        } else {
            return false;
        }
    }
}

console.log(isMatch('aa', 'a*'));
