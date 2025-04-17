class Solution {
public:
    vector<vector<int>> g;
    vector<vector<int>> vis;
    int n, m;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    // Corrected: Pass g by reference to avoid copying the whole grid
    int ck(int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m && g[i][j] == 1 && vis[i][j] == 0);
    }

    void bfs(queue<pair<int, int>>& q, int& time) {
        while (!q.empty()) {
            int sz = q.size();
            bool progressed = false;

            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int ni = i + dx[d];
                    int nj = j + dy[d];

                    if (ck(ni, nj)) {
                        vis[ni][nj] = 1;
                        g[ni][nj] = 2; // Make the orange rotten
                        q.push({ni, nj});
                        progressed = true;

    // We don't increment time here because we're still in the same BFS level (same minute).
    // Time should be incremented only **after all oranges of the current level** are processed.
                    }
                }
            }
     // all oranges of this label are rotten
            if (progressed) time++;
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        g = grid;
        n = g.size();
        m = g[0].size();
        vis.assign(n, vector<int>(m, 0));

        queue<pair<int, int>> q; // initial position of rotten oranges
 

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (g[i][j] == 2) 
                {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }

        int time = 0;
        bfs(q, time);

    //    if still any fresh orange left  

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (g[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};
