class Solution {
    // Shared precomputed lookup table for numbers 0 to 1000
    private static final int[] DIGIT_SUM_LOOKUP = new int[1001];

    // Static block executes once when the class is loaded
    static {
        for (int i = 0; i <= 1000; i++) {
            DIGIT_SUM_LOOKUP[i] = (i / 1000) + ((i / 100) % 10) + ((i / 10) % 10) + (i % 10);
        }
    }

    public int smallestIndex(int[] nums) {
        // Limit the search bounds because the max possible digit sum for nums[i] <= 1000 is 27 (for 999)
        int limit = Math.min(nums.length, 28); 

        for (int i = 0; i < limit; i++) {
            // O(1) array access instead of mathematical loops
            if (DIGIT_SUM_LOOKUP[nums[i]] == i) {
                return i; 
            }
        }
        
        return -1;
    }
}
