class Solution {
public:
    void bfs(vector<vector<int>>& adj, int n, vector<int>& vis) {

        vis[n] = 1;

        queue<int> q;
        q.push(n);

        while(!q.empty()) {

            int tp = q.front();
            q.pop();

            for(int x : adj[tp]) {

                if(!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<vector<int>> adj(n);  

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++) {

                if(isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);

        int cnt = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                bfs(adj, i, vis);
                cnt++;
            }
        }

        return cnt;
    }
};