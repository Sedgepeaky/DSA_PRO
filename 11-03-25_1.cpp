Shortest path in Directed Acyclic Graph

class Solution {
    public:
      void topoSortDFS(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
          vis[node] = 1;
          for (auto it : adj[node]) {
              int v = it.first;
              if (!vis[v]) {
                  topoSortDFS(v, adj, vis, st);
              }
          }
          st.push(node);
      }
      
      
      vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
          vector<pair<int,int>> adj[V];
          for(int i = 0 ; i<E ; i++){
              int u = edges[i][0];
              int v= edges[i][1];s
              int wt = edges[i][2];
              
              adj[u].push_back({v,wt});
          }
          
      // STEP 1 TOPO SORT 
      
          vector<int> vis(V, 0);
          stack<int> st;
          
          topoSortDFS(0, adj, vis, st);
      // STEP 2 
          
         
          
          vector<int> dis(V,INT_MAX);
          
          dis[0] = 0;
          while(!st.empty()){
              int node = st.top();
              st.pop();
              
              
              for(auto it : adj[node]){
                  int v = it.first;
                  int wt = it.second;
                  
                  if(dis[node] + wt<dis[v]){
                      dis[v] = dis[node] + wt;
                  }
                  
              }
          }
          for(int i = 0 ; i<V ; i++) {
              if(dis[i] == INT_MAX) dis[i] = -1;
          }
          
         
          return dis;
          
      
      
      }
  };

  APPROACH : DFS
  TC : O(V+E)
  SC : O(V+E)