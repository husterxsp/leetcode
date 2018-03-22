class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
    	int left = 0, right = letters.length - 1, mid = 0;
    	while (left < right) {
    		mid = left + (right - left) / 2;
    		if (letters[mid] > target) {
    			right = mid;
    		}
    		else {
    			left = mid + 1;
    		}
    	}
		return letters[left] > target ? letters[left] : letters[0];
    }
}