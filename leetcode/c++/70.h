class Solution {
public:
    int climbStairs(int n) {
        int* dp = new int[n+1];
        for(int i=0; i<=n; i++){
            dp[i] = -1;
        }
        return dynamic_planning(n, dp);
    }
    
    int dynamic_planning(int n, int *dp){
        if(n == 0 || n == 1 || n == 2){
            if(dp[n] == -1)
                dp[n] = n;
            return n;
        }
        if(dp[n-1] == -1)
            dp[n-1] = dynamic_planning(n-1, dp);
        if(dp[n-2] == -1)
            dp[n-2] = dynamic_planning(n-2, dp);
        return dp[n-1] + dp[n-2];
    }
};