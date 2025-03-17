210. Course Schedule II

class Solution {
    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            vector <vector<int>> adj(numCourses);
            for(auto it : prerequisites){
                adj[it[1]].push_back(it[0]);
            }
    // KAHNS ALGO(BFS)
            int n = adj.size();
            vector<int> ans;
            
            vector<int> indegree(numCourses ,0);
            
            for(int i = 0 ; i<n ; i++){
                for(auto it : adj[i]){
                    indegree[it] ++;
                }
            }
            
            // main step 2;
            queue<int> q;
            for(int i = 0 ; i<n ; i++){
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
            
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
                
                for(auto it: adj[node]){
                    indegree[it] --;
                    if(indegree[it] == 0){
                        q.push(it);
                    }
                }
            }
            return (ans.size() == n) ? ans:vector<int>();       
        }
    };

    APPROACH : KAHNS ALGO(BFS)

    TC : O(V+E)
    SC : O(V+E)