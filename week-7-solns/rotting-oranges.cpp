class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        if (grid.empty() || grid[0].empty()) {
            return -1;
        }

        int total = 0, count = 0;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<tuple<int, int, int>> q;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (int i = 0 ; i < m ; i++) {
            for (int j = 0 ; j < n ; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                    count++;
                }

                if (grid[i][j]) {
                    total++;
                }
            }
        }

        int ans = 0;

        while(!q.empty()) {
            auto [x, y, z] = q.front();
            q.pop();

            for(auto [i, j] : dir) {
                int new_r = x + i;
                int new_c = y + j;

                if (new_r >= 0 && new_c >= 0 && new_r < m && new_c < n && grid[new_r][new_c] == 1) {
                    if (dist[new_r][new_c] >= z + 1) {
                        grid[new_r][new_c] = 2;
                        dist[new_r][new_c] = z + 1;
                        ans = max(ans, z + 1);
                        q.push({new_r, new_c, z + 1});
                        count++;
                    }
                }
            }
        }

        if (count == total) {
            return ans;
        }
        else {
            return -1;
        }
    }
};