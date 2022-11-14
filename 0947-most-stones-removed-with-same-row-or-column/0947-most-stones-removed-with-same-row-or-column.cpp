class Solution {
public:
    bool check(vector<int> &stones1,vector<int> &stones2){
        if(stones1[0]==stones2[0]||stones1[1]==stones2[1])return true;
        return false;
    }
    void dfs(vector<int> &visited,vector<vector<int>> &stones, int index){
        visited[index]=1;
        for(int i = 0;i<stones.size();i++){
            if(!visited[i]&&check(stones[i],stones[index]))
                dfs(visited,stones,i);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> visited(n,0);
        int components = 0;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(visited,stones,i);
            }
        }
        return n-components;
    }
};