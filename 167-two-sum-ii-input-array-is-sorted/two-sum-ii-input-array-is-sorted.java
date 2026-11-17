class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int left = 0;
        int right = numbers.length - 1;

        while (left < right) {
            int sum = numbers[left] + numbers[right];

            if (sum == target) {
                // Add +1 because the problem specifies a 1-indexed answer
                return new int[]{left + 1, right + 1};
            } else if (sum < target) {
                left++;  // Need a larger sum -> move right
            } else {
                right--; // Need a smaller sum -> move left
            }
        }

        // Guaranteed one solution exists, so this fallback is just for Java's compiler
        return new int[]{-1, -1};
    }
}
