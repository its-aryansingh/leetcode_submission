#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        long long total_lcm = 1;
        int max_val = 0;
        
        for (int num : nums) {
            total_lcm = lcm(total_lcm, (long long)num);
            max_val = max(max_val, num);
        }
        
        // Maximum possible product for any valid subarray
        long long max_p = total_lcm * max_val;
        
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            long long p = 1;
            long long g = 0;
            long long l = 1;
            
            for (int j = i; j < n; ++j) {
                p *= nums[j];
                g = gcd(g, (long long)nums[j]);
                l = lcm(l, (long long)nums[j]);
                
                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                }
                
                // Break early to prevent long long overflow
                if (p > max_p) {
                    break;
                }
            }
        }
        
        return ans;
    }
};