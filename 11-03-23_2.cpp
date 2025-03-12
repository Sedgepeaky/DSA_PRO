Dijkstra Algorithm

class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
         
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
          vector<int> dist(adj.size(),1e9);
          
          dist[src] = 0;
          minHeap.push({0,src});
          
          while(!minHeap.empty()){
              int dis = minHeap.top().first;
              int node = minHeap.top().second;
              minHeap.pop();
              
              for(auto it : adj[node]){
                  int v = it.first;
                  int wt = it.second;
                  if(dis + wt < dist[v]){
                      dist[v] = dis+wt;
                      minHeap.push({dist[v],v});
                  }
              }
          }
          return dist;
          
          
      // SET
      /*
          int n = adj.size();
          set<pair<int,int>> s;
          vector<int> dis(n,1e9);
          dis[src] = 0;
          s.insert({0,src});
          
          while(!s.empty()){
              auto it = * (s.begin());
              int node = it.second;
              int val = it.first;
              s.erase(it);
              
              for(auto it : adj[node]){
                  int v = it.second;
                  int wt = it.first;
                  if(val+wt<dis[v]){
                      if (dis[v] != 1e9) {
                          s.erase({dis[v], v});
                      }
                      dis[v] = val +wt;
                      s.insert({dis[v],v});
                  
                  }
                  
                  
              }
              
          }
          return dis;
          */
      }
  };

  APPROACH : Dijkstra Algorithm
  TC : E(log V)
  SC : O(V + E)
