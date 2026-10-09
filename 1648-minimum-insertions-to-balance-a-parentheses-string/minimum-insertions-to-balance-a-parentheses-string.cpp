class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed_right = 0;
        
        for (char c : s) {
            if (c == '(') {
                // If we need an odd number of ')', it means a previous '(' 
                // only got one ')'. We must insert one ')' to balance it.
                if (needed_right % 2 != 0) {
                    insertions++;
                    needed_right--;
                }
                // Each '(' requires two ')'
                needed_right += 2;
            } else {
                // c == ')'
                if (needed_right > 0) {
                    needed_right--;
                } else {
                    // We found a ')' but have no matching '('.
                    // We must insert a '(' (1 insertion) which requires two ')'.
                    // Since we just encountered one ')', we now need 1 more ')'.
                    insertions++;
                    needed_right = 1;
                }
            }
        }
        
        // Add any remaining required ')' to the total insertions
        return insertions + needed_right;
    }
};
