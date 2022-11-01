class Solution {
public:
    void pass(vector<vector<int>>&grid,int row,int col,int c,vector<int> &ans){
        int m = grid[0].size(), n = grid.size();
        if(grid[row][col]==1){
            if(col+1<m&&grid[row][col+1]==1){
                if(row+1==n)ans[c]=col+1;
                else pass(grid,row+1,col+1,c,ans);
            }
            else ans[c] = -1;
        }
        if(grid[row][col]==-1){
            if(col-1>=0&&grid[row][col-1]==-1){
                if(row+1==n)ans[c]=col-1;
                else pass(grid,row+1,col-1,c,ans);
            }
            else ans[c] = -1;
        }
        
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid[0].size(), n = grid.size();
        vector<int>ans(m,0);
        for(int i =0;i<m;i++){
            pass(grid,0,i,i,ans);
        }
        return ans;
    }
};