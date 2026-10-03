#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        int max_len = 0;
        std::stack<int> st;
        st.push(-1); // Base index for calculating lengths
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' is unmatched; it becomes the new boundary
                    st.push(i);
                } else {
                    // Valid substring formed, calculate length
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }
        return max_len;
    }
};
