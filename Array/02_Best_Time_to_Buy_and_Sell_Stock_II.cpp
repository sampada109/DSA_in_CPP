// Best Time to Buy and Sell Stock II
// Ouestion Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = 0, maxi = 0, profit = 0;
        
        int i = 1;
        
        while(i < prices.size()){
            
            if(mini > maxi){
                maxi = mini;
            }
            
            mini = min(prices[i], prices[i-1]);
            maxi = max(maxi, prices[i]-mini);
            profit += prices[i]-mini;
            
            i++;
        }
        
        return profit;
    }
};
