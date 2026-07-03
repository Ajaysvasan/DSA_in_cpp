#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int mod = 1e9 + 7;
    int dfs(int n, char lastChar, int idx, unordered_map<char, vector<char>> &mpp, vector<vector<int>> &memo)
    {
        if (idx == n)
            return 1;
        if (memo[idx][lastChar - 'a'] != -1)
            return memo[idx][lastChar - 'a'];
        int count = 0;
        for (auto &nextChar : mpp[lastChar])
        {
            count = (count + dfs(n, nextChar, idx + 1, mpp, memo)) % mod;
        }
        return memo[idx][lastChar - 'a'] = count;
    }

public:
    int countVowelPermutation(int n)
    {
        vector<vector<int>> memo(n + 1, vector<int>(26, -1));
        unordered_map<char, vector<char>> mpp;
        mpp['a'] = {'e'};
        mpp['e'] = {'a', 'i'};
        mpp['i'] = {'a', 'e', 'o', 'u'};
        mpp['o'] = {'i', 'u'};
        mpp['u'] = {'a'};
        int total = 0;
        for (auto &c : mpp)
            total = (total + dfs(n, c.first, 1, mpp, memo)) % mod;
        return total % mod;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    int n = 5;
    cout << sol.countVowelPermutation(n) << endl;
    return 0;
}
