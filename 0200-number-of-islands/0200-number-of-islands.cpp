class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        // Boundary + water + already visited
        if (i < 0 || i >= n || j < 0 || j >= m ||
            grid[i][j] == '0' || vis[i][j] == 1)
            return;

        // Mark visited
        vis[i][j] = 1;

        // Up
        dfs(grid, i - 1, j, vis);

        // Down
        dfs(grid, i + 1, j, vis);

        // Left
        dfs(grid, i, j - 1, vis);

        // Right
        dfs(grid, i, j + 1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1' && vis[i][j] == 0) {

                    count++;

                    dfs(grid, i, j, vis);
                }
            }
        }

        return count;
    }
};