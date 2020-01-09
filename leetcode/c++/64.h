class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();//row
        int n = grid[0].size();//column
        
        if(m == 0 && n == 0)
            return grid[0][0];
        
        for(int i=1; i<m; i++){//n == 0
            grid[i][0] += grid[i-1][0];
        }
        for(int i=1; i<n; i++){//m == 0
            grid[0][i] += grid[0][i-1];
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        
        return grid[m-1][n-1];
    }
};