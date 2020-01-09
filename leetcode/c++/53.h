class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int* dp = new int[n];
        int max_num = 0xFFFFFFFF;
        
        if(n == 0)
            return 0;
        dp[0] = nums[0];
        max_num = nums[0];
        
        for(int i=1; i<n; i++){
            dp[i] = max(nums[i], nums[i]+dp[i-1]);
            if(dp[i] > max_num)
                max_num = dp[i];
        }
        
        return max_num;
    }
};