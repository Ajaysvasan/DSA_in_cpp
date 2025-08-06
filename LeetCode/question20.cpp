#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int buy = INT_MAX;
        int profit = 0;
        for(int i = 0;i<prices.size();i++){
            buy = std::min(buy , prices[i]);
            profit = std::max(profit , prices[i] - buy);
        }
        return profit;
    }
};