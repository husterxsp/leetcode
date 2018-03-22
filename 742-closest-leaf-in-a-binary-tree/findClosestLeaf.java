/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int findClosestLeaf(TreeNode root, int k) {

    }
}


package test;

import java.util.*;
import java.lang.*;

public class Solution {
	public class TreeNode {
	     int val;
	     TreeNode left;
	     TreeNode right;
	     TreeNode(int x) { val = x; }
	}
	public static int help(TreeNode root) {
		if (root == null) return 1;
		return Math.min(help(root.left), help(root.right));
	}
	public static void getDepth(TreeNode root) {

	}
    public static int findClosestLeaf(TreeNode root, int k) {
    	if (root.val == k) {
   		 	return help(root);
    	}
    	if (root.left != null) {
           int ret = findClosestLeaf(root.left, k);
           if (ret != 0) return ret;
       }
       if (root.right != null) {
           int ret = findClosestLeaf(root.right, k);
           if (ret != 0) return ret;
       }
       return 0;
    }
	public static void main(String[] args) {
		Solution s = new Solution();

    	TreeNode tree = s.new TreeNode(1);
    	tree.right = s.new TreeNode(3);

    	tree.left = s.new TreeNode(2);


    }

}
