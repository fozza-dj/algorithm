class Solution {
public:
    int min_size;
int error = 0x7ffffffe;
    
    int dynamic_planning(vector<int>& coins, int* dp, int n){
    if(n == 0)
        return 0;
    if(dp[n] != -1)
        return dp[n];
    if(n < min_size)
        return error;

    int min = 0x7FFFFFFF; 
    for (int i = coins.size() - 1; i >= 0; i--){
        int tmp;
        if(n - coins[i] >= 0){
            int ret = dynamic_planning(coins, dp, n - coins[i]);
            tmp = (ret == error) ? error : ret + 1;
        }
            
        else
            tmp = error;
        if(min > tmp){
            min = tmp;
            dp[n] = tmp;
        }
    }

    return dp[n];
}
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
    int *dp = new int[amount+1]();

    for (int i = 1; i <= amount; i++){//f(0) = 0
        dp[i] = -1;
    }
    
    //if unsorted
    sort(coins.begin(), coins.end());

    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
            dp[coins[i]] = 1;
    }

    min_size = coins[0];

    int min_num = dynamic_planning(coins, dp, amount);

    delete[] dp;

    if(min_num == error)
        return -1;
    return min_num;
    }
};