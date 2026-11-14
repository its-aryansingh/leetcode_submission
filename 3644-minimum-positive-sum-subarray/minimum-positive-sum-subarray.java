import java.util.List;

class Solution {
    public int minimumSumSubarray(List<Integer> nums, int l, int r) {
        int n = nums.size();
        int minSum = Integer.MAX_VALUE;

        // Check every valid subarray length from l to r
        for (int len = l; len <= r; len++) {
            int currentSum = 0;

            // Calculate the sum of the first window of size 'len'
            for (int i = 0; i < len; i++) {
                currentSum += nums.get(i);
            }

            if (currentSum > 0) {
                minSum = Math.min(minSum, currentSum);
            }

            // Slide the window across the rest of the list
            for (int i = len; i < n; i++) {
                currentSum += nums.get(i) - nums.get(i - len);
                if (currentSum > 0) {
                    minSum = Math.min(minSum, currentSum);
                }
            }
        }

        // Return -1 if no subarray had a strictly positive sum
        return minSum == Integer.MAX_VALUE ? -1 : minSum;
    }
}
