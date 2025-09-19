// problem link --

// https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/?envType=problem-list-v2&envId=shortest-path

// Dijkstra 

// code -- 


class Solution {
public:
    #define pp pair<int,int>
    #define p pair<int,pp> 
    int minimumTime(vector<vector<int>>& grid) {
        priority_queue<p,vector<p>,greater<p> >pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int> >value(n,vector<int>(m,INT_MAX));
        value[0][0]=0;
        pq.push({0,{0,0}});
        vector<vector<int> > direction({{0,1},{1,0},{0,-1},{-1,0}});
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        while(!pq.empty()){
            int val=pq.top().first;
            int idxi=pq.top().second.first;
            int idxj=pq.top().second.second;
            pq.pop();
            for(auto& dir: direction){
                int newi=idxi+dir[0];
                int newj=idxj+dir[1];
                if(newi>=0 && newi<n && newj>=0 && newj<m){
                    int newcost=val+1;
                    if(newcost<grid[newi][newj]){
                        if((newcost-1)%2 != (grid[newi][newj])%2) newcost=grid[newi][newj];
                        else newcost=grid[newi][newj]+1;
                    } 
                    if(newcost<value[newi][newj]){
                        value[newi][newj]=newcost;
                        pq.push({newcost,{newi,newj}});
                    }
                }
            }
        }
    return value[n-1][m-1];
    }
};