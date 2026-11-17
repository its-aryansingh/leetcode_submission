class Solution {

    public int removeDuplicates(int[] nums) {

        // If array has at most 2 elements,
        // all are already valid.
        if (nums.length <= 2)
            return nums.length;

        /*
         * write points to the next position
         * where we can write a valid element.
         *
         * First two elements are always allowed.
         */
        int write = 2;

        /*
         * Start reading from the third element.
         */
        for (int read = 2; read < nums.length; read++) {

            /*
             * Compare current element with the
             * element two positions behind write.
             *
             * If they are different,
             * current element can be kept.
             */
            if (nums[read] != nums[write - 2]) {

                nums[write] = nums[read];
                write++;
            }
        }

        /*
         * write represents the number of
         * valid elements.
         */
        return write;
    }
}