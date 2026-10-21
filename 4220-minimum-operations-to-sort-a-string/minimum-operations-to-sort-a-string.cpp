#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int minOperations(std::string s) {
        // 0 Operations: Already sorted
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        int n = s.length();
        // -1 Operations: Length 2 and not sorted (proper substrings cannot reorder it)
        if (n == 2) {
            return -1;
        }
        
        // Find the absolute minimum and maximum characters in the string
        char min_char = s[0];
        char max_char = s[0];
        for (char c : s) {
            min_char = std::min(min_char, c);
            max_char = std::max(max_char, c);
        }
        
        // 1 Operation: If the absolute minimum is at the front, 
        // or the absolute maximum is at the back.
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }
        
        // 2 Operations: If any instance of the absolute minimum or maximum 
        // lies strictly in the interior of the string.
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == min_char || s[i] == max_char) {
                return 2;
            }
        }
        
        // 3 Operations: The minimum is only at the end and the maximum is only at the beginning
        return 3;
    }
};
