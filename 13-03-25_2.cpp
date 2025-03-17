Q2 GRAPHS
787. Cheapest Flights Within K Stops

class Solution {
    public:
        int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
    // MAKING ADJ LIST
            vector<vector<pair<int,int>>> adj(n);
            for(auto it: flights){
                adj[it[0]].push_back({it[1], it[2]});
    
            }
    // PQ
            queue<pair<int,pair<int,int>>>q;
            q.push({0,{src,0}});
            vector <int> dis(n,1e9);
            dis[src ] = 0;
    
            while(!q.empty()){
                auto it = q.front();
                q.pop();
                int stops = it.first;
                int node = it.second.first;
                int cost = it.second.second;
                if(stops > k) continue;
                for(auto itr : adj[node]){
                    int adjnode = itr.first;
                    int wt = itr.second;
    
                    if(cost+wt < dis[adjnode]){
                        dis[adjnode] = cost +wt;
                        q.push({stops+1,{adjnode, cost +wt}});
                    }
    
                }
            }
            if(dis[dst ] == 1e9) return -1;
            return dis[dst];
    
            
        }
    };
    Approach : BFS
    TC : O(K.E)
    SC : O(V+E)
