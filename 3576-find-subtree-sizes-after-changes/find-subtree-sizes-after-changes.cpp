#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; ++i) {
            children[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> last_seen(26, -1);

        auto dfs = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int closest_anc = last_seen[char_idx];

            last_seen[char_idx] = u;

            for (int v : children[u]) {
                self(self, v);
            }

            last_seen[char_idx] = closest_anc;

            int target_parent = (closest_anc != -1) ? closest_anc : parent[u];
            if (target_parent != -1) {
                ans[target_parent] += ans[u];
            }
        };

        dfs(dfs, 0);
        return ans;
    }
};
