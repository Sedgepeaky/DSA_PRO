class Solution {
    private:
      void dfs(int node , vector<int>& vis , vector<vector<int>>& adj ){
          vis[node] = 1;
          
          for (int j = 0; j < adj.size(); j++) {
              if (adj[node][j] == 1 && !vis[j]) {
                  dfs(j, vis, adj);
              }
          }
      }
    public:
      int numProvinces(vector<vector<int>> adj, int V) {
          
          int n = adj.size();
          vector<int> vis(n,0);
          int count = 0;
          
          for(int i = 0 ; i<n ; i++){
              if(vis[i] == 0){
                  count ++;
                  dfs(i,vis,adj);
              }
          }
          return count;
      }
  };
  