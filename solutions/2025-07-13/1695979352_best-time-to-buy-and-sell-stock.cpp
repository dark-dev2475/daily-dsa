class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int min_price=prices[0];
        // int max_price=0;
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            min_price=min(min_price,prices[i]);
            max_profit=max(max_profit,prices[i]-min_price);
        }
        return max_profit;
    }

       
      
};