import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {

    // Safe infinity value that won't overflow when adding costs
    private static final int INF = 1_000_000;

    public int minimumChanges(String s, int k) {
        int n = s.length();
        char[] chars = s.toCharArray();

        // STEP 1: Precompute valid proper divisors (1 <= d < len) for every possible length
        List<Integer>[] divisors = getDivisorsUpTo(n);

        // STEP 2: Precompute minCost[i][j] = min changes to make s[i..j] a semi-palindrome
        int[][] minCost = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(minCost[i], INF);
            // Substrings of length 1 (j == i) stay INF because they cannot be semi-palindromes!
            for (int j = i + 1; j < n; j++) {
                minCost[i][j] = computeSemiPalindromeCost(chars, i, j, divisors[j - i + 1]);
            }
        }

        // STEP 3: Partition DP
        // dp[p][i] = min changes to split first 'i' chars (s[0..i-1]) into 'p' substrings
        int[][] dp = new int[k + 1][n + 1];
        for (int p = 0; p <= k; p++) {
            Arrays.fill(dp[p], INF);
        }

        // Base case: p = 1 substring covering s[0..i-1] (must have length i >= 2)
        for (int i = 2; i <= n; i++) {
            dp[1][i] = minCost[0][i - 1];
        }

        // Fill DP for p = 2 up to k partitions
        for (int p = 2; p <= k; p++) {
            // Minimum prefix length for 'p' pieces of size >= 2 is (2 * p)
            for (int i = 2 * p; i <= n; i++) {
                // 'prev' is the cut point:
                // - First (p - 1) pieces need at least 2 * (p - 1) chars
                // - Last piece s[prev .. i-1] needs at least 2 chars (so prev <= i - 2)
                for (int prev = 2 * (p - 1); prev <= i - 2; prev++) {
                    if (dp[p - 1][prev] != INF) {
                        int candidate = dp[p - 1][prev] + minCost[prev][i - 1];
                        dp[p][i] = Math.min(dp[p][i], candidate);
                    }
                }
            }
        }

        return dp[k][n];
    }

    /**
     * Helper 1: Precomputes all valid divisors d (1 <= d < len) for lengths 2..n
     */
    @SuppressWarnings("unchecked")
    private List<Integer>[] getDivisorsUpTo(int maxLen) {
        List<Integer>[] divisors = new ArrayList[maxLen + 1];
        for (int len = 0; len <= maxLen; len++) {
            divisors[len] = new ArrayList<>();
        }
        // Standard sieve-style loop: for each d, add d to all multiples 2*d, 3*d, ...
        for (int d = 1; d < maxLen; d++) {
            for (int len = 2 * d; len <= maxLen; len += d) {
                divisors[len].add(d);
            }
        }
        return divisors;
    }

    /**
     * Helper 2: Finds min letter changes for substring chars[start..end] across all valid divisors
     */
    private int computeSemiPalindromeCost(char[] chars, int start, int end, List<Integer> validDivisors) {
        int bestChanges = INF;

        for (int d : validDivisors) {
            int changesForDivisor = 0;

            // Check each of the 'd' repeating groups: (offset, offset + d, offset + 2d, ...)
            for (int offset = 0; offset < d; offset++) {
                int left = start + offset;
                int right = end - d + 1 + offset; // Matching bottom index in the same modulo group

                // Two-pointer palindrome check stepping by 'd'
                while (left < right) {
                    if (chars[left] != chars[right]) {
                        changesForDivisor++;
                    }
                    left += d;
                    right -= d;
                }
            }

            bestChanges = Math.min(bestChanges, changesForDivisor);
            if (bestChanges == 0) {
                break; // Early exit optimization: can't beat 0 changes!
            }
        }

        return bestChanges;
    }
}
