/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

//方法1，两层遍历
var twoSum1 = function (nums, target) {
    for (var i = 0; i < nums.length; i++) {
        for (var j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] == target) {
                return [i, j];
            }
        }
    }
};

//方法2，先排序，再查找
var twoSum2 = function (nums, target) {
    var length = nums.length;
    var arr = [];
    for (var i = 0; i < length; i++) {
        arr.push({
            key: i,
            val: nums[i]
        });
    }

    delete nums;

    //使用自己写的排序，leetcode结果显示内存超出限制。。。
    // arr = sort(arr);

    arr.sort(function (value1, value2) {
        return value1.val - value2.val;
    });

    for (i = 0; i < arr.length; i++) {
        var searchResult = binarySearch(arr, target - arr[i].val, arr[i].key);
        if (searchResult.key !== -1) {
            if (arr[i].key == searchResult.key) {

            }
            return [arr[i].key, searchResult.key].sort();
        }
    }

    // function sort(arr) {
    //     if (arr.length == 0) {
    //         return [];
    //     }
    //     var less = [];
    //     var great = [];
    //     var pivot = arr[0];
    //     for (var i = 1; i < arr.length; i++) {
    //         if (arr[i].val < pivot.val) {
    //             less.push(arr[i]);
    //         } else if (arr[i].val > pivot.val) {
    //             great.push(arr[i]);
    //         }
    //     }
    //     return sort(less).concat(pivot, sort(great));
    // }

    function binarySearch(arr, num, key) {
        var start = 0;
        var end = arr.length - 1;
        while (start <= end) {
            var mid = Math.floor((start + end) / 2);
            if (num < arr[mid].val) {
                end = mid - 1;
            } else if (num > arr[mid].val) {
                start = mid + 1;
            } else if (arr[mid].key !== key) {
                return arr[mid];
            } else {
                return {
                    key: -1,
                    val: -1
                };
            }
        }
        return {
            key: -1,
            val: -1
        };
    }
};

//方法三，使用map, 以下代码还有点问题
var twoSum3 = function (nums, target) {
    var length = nums.length;
    var map = new Map();
    for (var i = 0; i < length; i++) {
        map.set([nums[i]], i);
    }

    for (var i = 0; i < length; i++) {
        var complement = target - nums[i];
        if (map.has([complement]) && map.get([complement]) !== i) {
            console.log([i, map.get([complement])])
        }
    }
}
console.log(twoSum2([2, 1, 9, 4, 4, 56, 90, 3], 8));
