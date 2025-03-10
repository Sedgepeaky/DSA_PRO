802. Find Eventual Safe States
class Solution {
    public:
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n = graph.size();
            queue<int> q;
            vector<int> outdegree(n,0);
            vector<vector<int>> revGraph(n);
            vector<int> ans;
            
            for(int i = 0 ; i<n;i++){
                for (int neighbor : graph[i]) {
                    revGraph[neighbor].push_back(i); // Reverse the edge
                }
                outdegree[i]= graph[i].size();
            }
        // for terminal node
            for(int i = 0 ; i<n ; i++){
                if(outdegree[i] == 0){
                    q.push(i);
                }
            }
        // safe nodes
            while(!q.empty()){
                int node = q.front();
                q.pop();
                ans.push_back(node);
    
                for(auto it : revGraph[node]){
                    outdegree[it] --;
                    if(outdegree[it] == 0){
                        q.push(it);
                    }
                }
            }
            sort(ans.begin(),ans.end());
            return ans;
            
        }
    };
    TC : O(V+E)
    SC: O(V+E)
    APPROACH : BFS