Shortest Path in Undirected
class Solution {
    public:
      // Function to find the shortest path from source to all other nodes
      vector<int> shortestPath(vector<vector<int>>& adj, int src) {
          
          int n = adj.size();
          queue<pair<int,int>> q;
          vector<int> dis(n,1e9);
          dis[src] = 0;
          q.push({src,0});
          while(!q.empty()){
              int node = q.front().first;
              int distance = q.front().second;
              
              q.pop();
              dis[node] = distance;
              
              for(auto it: adj[node]){
                  if(dis[node] + 1 < dis[it]){
                      dis[it] = distance +1;
                      q.push({it,dis[it]});
                  }
              }
          }
          vector<int> ans(n,-1);
          
          for(int i = 0 ; i<n ; i++){
              if(dis[i] != 1e9){
                  ans[i] = dis[i];
              }
              else{
                  ans[i] = -1;
              }
          }
          return ans;
      }
  };
  TC : O(V+E)
  SC: O(V+E)
  APPROACH : BFS