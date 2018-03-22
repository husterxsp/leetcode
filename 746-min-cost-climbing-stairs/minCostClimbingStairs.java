class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int size = cost.length + 1;
        int[] dp = new int[size];

        for (int i = 2; i < size; i++) {
            dp[i] = Math.min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
		return dp[size - 1];
    }
}
