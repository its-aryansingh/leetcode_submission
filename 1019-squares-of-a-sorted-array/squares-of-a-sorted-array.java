class Solution {
    public int[] sortedSquares(int[] nums) {

        int[] result = new int[nums.length];


        int left =0;

        int right = nums.length -1;


        int write
         = nums.length- 1;


        while(left <= right){
            if(Math.abs(nums[left]) > Math.abs(nums[right])){
                result[write] = nums[left] * nums[left];

                left++;
            }
            else{
                result[write] = nums[right]*nums[right];
                right--;
            }

            write--;
        }
        return result;
        
    }
}