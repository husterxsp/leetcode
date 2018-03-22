import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
    	List<Integer> ret = new ArrayList();
        for (int i = left;i <= right; i++) {
            int cur = i;
            while (cur != 0) {
            	int remain = cur % 10;
            	
            	if (remain == 0 || i % remain != 0) break;
            	
            	cur /= 10;
            }
            if (cur == 0) ret.add(i);
        }
    	
		return ret;
    }
}