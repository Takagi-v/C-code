class Solution
{
public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
  {
    int m = maze.size();
    int n = maze[0].size();
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    queue<tuple<int, int, int>> q;
    q.emplace(entrance[0], entrance[1], 0);
    maze[entrance[0]][entrance[1]] = '+';
    while (!q.empty())
    {
      auto [cx, cy, d] = q.front();
      q.pop();
      for (int k = 0; k < 4; k++)
      {
        int nx = cx + dx[k];
        int ny = cy + dy[k];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.')
        {
          if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1)
          {
            return d + 1;
          }
          maze[nx][ny] = '+';
          q.emplace(nx, ny, d + 1);
        }
      }
    }
    return -1;
  }
}