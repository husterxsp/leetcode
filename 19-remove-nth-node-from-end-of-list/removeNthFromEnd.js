/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function (head, n) {
    var pointer = head;
    var length = 1;
    while (pointer.next !== null) {
        pointer = pointer.next;
        length++;
    }
    if (length === n) {
        return head.next;
    }
    pointer = head;
    var index = length - n;
    while (index-- > 1) {
        pointer = pointer.next;
    }
    pointer.next = pointer.next.next;
    return head;
};

var l1 = {
    val: 1,
    next: {
        val: 2,
        next: null
    }
};

console.log(removeNthFromEnd(l1, 1));
