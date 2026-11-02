class Solution {
    public int minMoves(int[] nums) {
        int minVal = nums[0];
        for(int num : nums){
            minVal = Math.min(minVal, num);
        }

        int moves = 0;

        for(int num : nums){
            moves += num - minVal;
        }
        return moves;
        
    }
}