class Solution {
public:
    bool bfs(vector<vector<int>>& adj , int src , int dest,vector<int>&vis){
        vis[src] = 1;
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            if(vis[dest]) return true;
            for(int x : adj[tp]){
                if(!vis[x]){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,0);

        return bfs(adj,source,destination , vis);
        
    }
};