1631. Path With Minimum Effort
class Solution {
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    
            int n = heights.size();
            int m = heights[0].size();
    
            int dx[] = {0,1,0,-1};
            int dy[] = {1,0,-1,0};
    
            vector<vector<int>> dis(n,vector<int>(m,1e9));
            dis[0][0] = 0;
            pq.push({0,{0,0}});
    
            while(!pq.empty()){
                auto[diff,cell] = pq.top();
                auto[r,c] = cell;
                pq.pop();
    
                if(r == n-1 && c == m-1){
                    return diff;
                }
    
                for(int i = 0 ; i<4;i++){
                    int nr = r+dx[i];
                    int nc = c+dy[i];
    
                    if(nr<n && nr>=0 && nc<m && nc>=0){
                        int newEffort = max(abs(heights[nr][nc] - heights[r][c]),diff);
                        if(newEffort<dis[nr][nc]){
                            dis[nr][nc] = newEffort;
                            pq.push({newEffort,{nr,nc}});
                        }
                    }
                }
            }
            return 0;
        }
    };

    APPROACH : Dijkstra Algorithm

    TC : O(n*m*4)(log(n*m))
    SC : O(n*m)