#include <vector>
#include <string>

using namespace std;

// Fast I/O Optimization for Competitive Programming
auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
private:
    void backtrack(int open, int close, int n, string& curr, vector<string>& result) {
        // Base case: Valid string fully formed
        if (curr.length() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Choice 1: Add open bracket if available
        if (open < n) {
            curr.push_back('(');
            backtrack(open + 1, close, n, curr, result);
            curr.pop_back(); // Backtrack
        }

        // Choice 2: Add close bracket if it safely matches an open bracket
        if (close < open) {
            curr.push_back(')');
            backtrack(open, close + 1, n, curr, result);
            curr.pop_back(); // Backtrack
        }
    }

    // Helper to calculate the N-th Catalan Number dynamically in O(N) time
    int getCatalanNumber(int n) {
        long long catalan = 1;
        for (int i = 0; i < n; ++i) {
            catalan = catalan * (2 * n - i) / (i + 1);
        }
        return catalan / (n + 1);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        
        // Dynamically reserve the exact amount of memory needed 
        // to completely eliminate internal vector re-allocations.
        result.reserve(getCatalanNumber(n));

        // Allocate the string buffer size immediately
        string curr = "";
        curr.reserve(2 * n);

        // Start backtracking
        backtrack(0, 0, n, curr, result);
        return result;
    }
};

