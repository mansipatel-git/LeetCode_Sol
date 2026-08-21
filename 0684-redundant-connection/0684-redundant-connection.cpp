class Solution {
public:
    vector<int> ans;

    bool hascycle(vector<vector<int>>& adj,
                  int i,
                  int parent,
                  vector<int>& vis) {

        vis[i] = 1;

        for(int nei : adj[i]) {

            if(!vis[nei]) {

                if(hascycle(adj, nei, i, vis)) {
                    return true;
                }
            }
            else if(nei != parent) {

                ans = {i, nei};
                return true;
            }
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        vector<vector<int>> adj(n + 1);

        for(auto &e : edges) {

            int u = e[0];
            int v = e[1];

            // Add this edge
            adj[u].push_back(v);
            adj[v].push_back(u);

            // Check whether this edge created a cycle
            vector<int> vis(n + 1, 0);
            ans.clear();

            for(int node = 1; node <= n; node++) {

                if(!vis[node]) {

                    if(hascycle(adj, node, -1, vis)) {
                        return {u, v};
                    }
                }
            }
        }

        return {};
    }
};