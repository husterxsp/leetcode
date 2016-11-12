/**
 * Definition for singly-linked list.
 */
function ListNode(val) {
    this.val = val;
    this.next = null;
}
var l1 = {
    val: 2,
    next: {
        val: 4,
        next: {
            val: 3,
            next: null
        }
    }
};
var l2 = {
    val: 5,
    next: {
        val: 6,
        next: {
            val: 4,
            next: null
        }
    }
};
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers1 = function (l1, l2) {
    var carry = 0;
    var remainder = 0;
    var result = [];
    while (!(l1 === null && l2 === null)) {
        if (l1 === null) {
            l1 = new ListNode(0);
        } else if (l2 === null) {
            l2 = new ListNode(0);
        }
        sum = l1.val + l2.val + carry;
        carry = Math.floor(sum / 10);
        remainder = sum % 10;
        result.push(remainder);
        if (l1.next) {
            l1 = l1.next;
        } else {
            l1 = null;
        }
        if (l2.next) {
            l2 = l2.next;
        } else {
            l2 = null;
        }
    }
    if (carry !== 0) {
        result.push(carry);
    }
    return result;
};
var addTwoNumbers2 = function (l1, l2) {
    var carry = 0;
    var sum = 0;
    var result = new ListNode(0);
    var pointer = result;
    while (l1 !== null && l2 !== null) {
        sum = l1.val + l2.val + carry;
        carry = Math.floor(sum / 10);
        pointer.next = new ListNode(sum % 10);
        pointer = pointer.next;
        l1 = l1.next;
        l2 = l2.next;
    }
    while (l1 !== null) {
        sum = l1.val + carry;
        carry = Math.floor(sum / 10);
        pointer.next = new ListNode(sum % 10);
        pointer = pointer.next;
        l1 = l1.next;
    }
    while (l2 !== null) {
        sum = l2.val + carry;
        carry = Math.floor(sum / 10);
        pointer.next = new ListNode(sum % 10);
        pointer = pointer.next;
        l2 = l2.next;
    }
    if (carry !== 0) {
        pointer.next = new ListNode(carry);
    }
    return result.next;
};

console.log(addTwoNumbers2(l1, l2));
