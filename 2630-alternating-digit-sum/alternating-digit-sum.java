class Solution {
    public int alternateDigitSum(int n) {
        int oddSum = 0;
        int evenSum = 0;
        int position = 1; // 1-indexed from right

        while (n > 0) {
            int digit = n % 10; // Extract rightmost digit

            if (position % 2 == 0) {
                evenSum += digit;
            } else {
                oddSum += digit;
            }

            n /= 10;      // Remove rightmost digit
            position++;   // Move to next position
        }

        int totalDigits = position - 1;

        if (totalDigits % 2 != 0) {
            return oddSum - evenSum;  // Leftmost digit was at an odd position
        } else {
            return evenSum - oddSum;  // Leftmost digit was at an even position
        }
    }
}
