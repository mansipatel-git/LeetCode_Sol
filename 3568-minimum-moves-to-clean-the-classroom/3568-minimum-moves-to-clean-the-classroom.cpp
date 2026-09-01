class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int sr, sc;

        // Give every litter a number
        vector<vector<int>> id(m, vector<int>(n, -1));
        int litter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litter++;
                }
            }
        }

        int fullMask = (1 << litter) - 1;

        // visited[r][c][energy][mask]
        vector<vector<vector<vector<bool>>>> vis(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << litter, false)
                )
            )
        );

        // r, c, remaining energy, mask, moves
        queue<array<int, 5>> q;

        q.push({sr, sc, energy, 0, 0});

        vis[sr][sc][energy][0] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {

            auto [r, c, e, mask, moves] = q.front();
            q.pop();

            // All litter collected
            if (mask == fullMask) {
                return moves;
            }

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                // Outside grid
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                // Obstacle
                if (classroom[nr][nc] == 'X')
                    continue;

                // Need 1 energy to move
                if (e == 0)
                    continue;

                int ne = e - 1;
                int nmask = mask;

                // Collect litter
                if (classroom[nr][nc] == 'L') {
                    int idx = id[nr][nc];
                    nmask |= (1 << idx);
                }

                // Reset energy
                if (classroom[nr][nc] == 'R') {
                    ne = energy;
                }

                if (!vis[nr][nc][ne][nmask]) {

                    vis[nr][nc][ne][nmask] = true;

                    q.push({
                        nr,
                        nc,
                        ne,
                        nmask,
                        moves + 1
                    });
                }
            }
        }

        return -1;
    }
};