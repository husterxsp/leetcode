/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays1 = function (nums1, nums2) {
    var length1 = nums1.length,
        length2 = nums2.length,
        half = Math.floor((length1 + length2) / 2);
    nums = nums1.concat(nums2).sort(function (value1, value2) {
        return value1 - value2;
    });
    if ((length1 + length2) % 2 === 0) {
        return (nums[half] + nums[half - 1]) / 2;
    } else {
        return nums[half];
    }
};

//归并
var findMedianSortedArrays2 = function (nums1, nums2) {
    var i = 0,
        j = 0,
        result = [],
        length1 = nums1.length,
        length2 = nums2.length,
        half = Math.floor((length1 + length2) / 2);
    if (length1 === 0 && length2 === 0) {
        return 0;
    }
    while (i + j <= half) {
        if (nums1[i] === undefined && nums2[j] !== undefined) {
            result.push(nums2[j++]);
        } else if (nums1[i] !== undefined && nums2[j] === undefined) {
            result.push(nums1[i++]);
        } else if (nums1[i] < nums2[j]) {
            result.push(nums1[i++]);
        } else {
            result.push(nums2[j++]);
        }
    }
    if ((length1 + length2) % 2 === 0) {
        return (result[half] + result[half - 1]) / 2;
    } else {
        return result[half];
    }

};

//递归
var findMedianSortedArrays3 = function (nums1, nums2) {
    var length1 = nums1.length,
        length2 = nums2.length,
        half = Math.floor((length1 + length2) / 2);
    if ((length1 + length2) % 2 === 0) {
        return (findKth(nums1, nums2, half) + findKth(nums1, nums2, half + 1)) / 2;
    } else {
        return findKth(nums1, nums2, half + 1);
    }

    function findKth(arr1, arr2, k) {
        if (arr1.length > arr2.length) {
            return findKth(arr2, arr1, k);
        }
        if (arr1.length === 0) {
            return arr2[k - 1];
        }
        if (k === 1) {
            return Math.min(arr1[0], arr2[0]);
        }
        var pointerA = Math.min(Math.floor(k / 2), arr1.length),
            pointerB = k - pointerA;
        if (arr1[pointerA - 1] < arr2[pointerB - 1]) {
            return findKth(arr1.slice(pointerA), arr2, k - pointerA);
        } else if (arr1[pointerA - 1] > arr2[pointerB - 1]) {
            return findKth(arr1, arr2.slice(pointerB), k - pointerB);
        } else {
            return arr1[pointerA - 1];
        }
    }
};
console.log(findMedianSortedArrays3([1], [1]));
