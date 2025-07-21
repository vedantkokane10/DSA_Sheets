// Question = Leetcode - 121

int maxProfit(vector<int>& prices) {
    int ans = 0;
    int minValue = prices[0];
    for(auto x:prices){
        minValue = min(minValue, x);
        int currentProfit = x - minValue;
        ans = max(ans, currentProfit);
    }
    return ans;
}