#include <bits/stdc++.h>
using namespace std;

    int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY)
    {
        queue<pair<int, int>> q;
        q.push({startX, startY});
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        visited[startX][startY] = true;
        int moves = 0;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                const auto [r, c] = q.front();
                q.pop();
                if (r == goalX && c == goalY)
                    return moves;
                for (int j = 0; j < 4; j++)
                {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    while (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == '.')
                    {
                        if(visited[nr][nc]) break;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                    nr += dr[j];
                    nc += dc[j];
                }
            }
            moves++;
        }
        return -1;
    }

int main()
{
    vector<string> grid = {"...X.", ".X...", "...X.", ".....", "X...."};
    int startX = 0, startY = 0, goalX = 4, goalY = 4;
    cout << minimumMoves(grid, startX, startY, goalX, goalY) << endl;
    return 0;
}