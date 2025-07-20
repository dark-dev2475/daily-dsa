class Solution {
private:
    int dfs(int r, int c, vector<vector<int>>& grid) {
        long long m = grid.size();
        long long n = grid[0].size();

        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long current_value = grid[r][c];
        grid[r][c] = 0;

        long long  island_total = current_value;
        island_total += dfs(r + 1, c, grid);
        island_total += dfs(r - 1, c, grid);
        island_total += dfs(r, c + 1, grid);
        island_total += dfs(r, c - 1, grid);

        return island_total;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        long long m = grid.size();
        long long n = grid[0].size();
        long long divisible_island_count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long island_value = dfs(i, j, grid);
                    if (island_value % k == 0) {
                        divisible_island_count++;
                    }
                }
            }
        }
        
        return divisible_island_count;
    }
};