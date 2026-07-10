#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<int> pathExistenceQueries(int n, vector<int> &nums, int maxDiff, vector<vector<int>> &queries)
    {
        // Step 1: Get sorted unique values
        vector<int> U = nums;
        sort(U.begin(), U.end());
        U.erase(unique(U.begin(), U.end()), U.end());

        int m = U.size();

        // Quick lookup array: maps a value to its index in U
        // Since max value is 10^5, an array is faster than an unordered_map
        int max_val = U.back();
        vector<int> val_to_idx(max_val + 1, -1);
        for (int i = 0; i < m; i++)
        {
            val_to_idx[U[i]] = i;
        }

        // Step 2: Build Connected Components
        vector<int> comp(m, 0);
        int current_comp = 0;
        for (int i = 1; i < m; i++)
        {
            if (U[i] - U[i - 1] > maxDiff)
            {
                current_comp++;
            }
            comp[i] = current_comp;
        }

        // Step 3: Find the furthest rightward jump for each index
        vector<int> nxt(m, 0);
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            // Push j to the right as long as the jump is valid
            while (j + 1 < m && U[j + 1] <= U[i] + maxDiff)
            {
                j++;
            }
            nxt[i] = j;
        }

        // Step 4: Build Binary Lifting (Jump Pointers) Table
        int LOG = 18; // 2^17 > 100,000
        vector<vector<int>> up(m, vector<int>(LOG, 0));

        for (int i = 0; i < m; i++)
        {
            up[i][0] = nxt[i];
        }

        for (int k = 1; k < LOG; k++)
        {
            for (int i = 0; i < m; i++)
            {
                up[i][k] = up[up[i][k - 1]][k - 1];
            }
        }

        // Step 5: Process Queries
        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto &query : queries)
        {
            int u = query[0];
            int v = query[1];

            if (u == v || nums[u] == nums[v])
            {
                ans.push_back(0);
                continue;
            }

            int valX = min(nums[u], nums[v]);
            int valY = max(nums[u], nums[v]);

            int idxX = val_to_idx[valX];
            int idxY = val_to_idx[valY];

            // Check reachability
            if (comp[idxX] != comp[idxY])
            {
                ans.push_back(-1);
                continue;
            }

            // Binary Lifting: Find minimum jumps to reach >= idxY
            int jumps = 0;
            int curr = idxX;

            // Start from largest powers of 2 and work downwards
            for (int k = LOG - 1; k >= 0; k--)
            {
                if (up[curr][k] < idxY)
                {
                    curr = up[curr][k];
                    jumps += (1 << k);
                }
            }

            // After the loop, curr is the largest index < idxY.
            // We just need 1 more jump to reach or exceed idxY.
            ans.push_back(jumps + 1);
        }

        return ans;
    }
};