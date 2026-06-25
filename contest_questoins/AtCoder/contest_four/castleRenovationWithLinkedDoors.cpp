#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

const int N = 20;

// Structures to store our output formats
struct Door {
  int d, i, j, g;
};

struct Switch {
  int p, q, s;
};

vector<pair<int, int>> get_path(pair<int, int> start, pair<int, int> target,
                                bool blocked[N][N][2],
                                const vector<string> &grid) {
  queue<pair<int, int>> q;
  vector<vector<pair<int, int>>> parent(N, vector<pair<int, int>>(N, {-1, -1}));
  vector<vector<bool>> visited(N, vector<bool>(N, false));

  q.push(start);
  visited[start.first][start.second] = true;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    if (curr == target)
      break;

    for (int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i];
      int nc = curr.second + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        continue;
      if (grid[nr][nc] == '#')
        continue;

      // Door blocked check
      // d_type: 1 if moving horizontally, 0 if moving vertically
      int d_type = (dr[i] == 0) ? 1 : 0;
      int r_min = min(curr.first, nr);
      int c_min = min(curr.second, nc);

      if (blocked[r_min][c_min][d_type])
        continue;

      if (!visited[nr][nc]) {
        visited[nr][nc] = true;
        parent[nr][nc] = curr;
        q.push({nr, nc});
      }
    }
  }

  vector<pair<int, int>> path;
  if (!visited[target.first][target.second])
    return path; // Target Unreachable

  // Backtrack to build the path
  pair<int, int> curr = target;
  while (curr != start) {
    path.push_back(curr);
    curr = parent[curr.first][curr.second];
  }
  path.push_back(start);
  reverse(path.begin(), path.end());

  return path;
}

// BFS to find the distance to all reachable cells from a starting point
vector<vector<int>> get_all_reachable_distances(pair<int, int> start,
                                                bool blocked[N][N][2],
                                                const vector<string> &grid) {
  queue<pair<int, int>> q;
  vector<vector<int>> dist(N, vector<int>(N, -1));

  q.push(start);
  dist[start.first][start.second] = 0;

  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (!q.empty()) {
    auto curr = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nr = curr.first + dr[i];
      int nc = curr.second + dc[i];

      if (nr < 0 || nr >= N || nc < 0 || nc >= N)
        continue;
      if (grid[nr][nc] == '#')
        continue;

      int d_type = (dr[i] == 0) ? 1 : 0;
      int r_min = min(curr.first, nr);
      int c_min = min(curr.second, nc);

      if (blocked[r_min][c_min][d_type])
        continue;

      if (dist[nr][nc] == -1) {
        dist[nr][nc] = dist[curr.first][curr.second] + 1;
        q.push({nr, nc});
      }
    }
  }
  return dist;
}

// --- MAIN LOGIC ---

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n_input, m, k_input;
  if (!(cin >> n_input >> m >> k_input))
    return 0;

  vector<string> grid(N);
  for (int i = 0; i < N; ++i) {
    cin >> grid[i];
  }

  vector<Door> doors;
  vector<Switch> switches;

  // Tracks doors we have placed so we don't route through them during
  // generation
  bool blocked[N][N][2] = {false};
  // Tracks cells that already have a switch
  bool has_switch[N][N] = {false};

  // Start by targeting the throne
  pair<int, int> current_target = {N - 1, N - 1};

  // Construct the fetch quests sequentially
  for (int k = 0; k < k_input; ++k) {

    // 1. Find the natural shortest path to our current target
    auto path = get_path({0, 0}, current_target, blocked, grid);

    // If we can't reach the target, our maze is as complex as this logic can
    // make it.
    if (path.size() < 2)
      break;

    // 2. Pick a choke point (edge) to block with a CLOSED door.
    // We pick roughly the midpoint of the path to force the hero to walk deep
    // into the maze.
    int edge_idx = path.size() / 2;
    auto u = path[edge_idx];
    auto v = path[edge_idx + 1];

    int d = (u.first == v.first) ? 1 : 0; // 1 if horizontal edge, 0 if vertical
    int i_coord = min(u.first, v.first);
    int j_coord = min(u.second, v.second);

    // Door type 2k+1 is initially CLOSED.
    doors.push_back({d, i_coord, j_coord, 2 * k + 1});
    blocked[i_coord][j_coord][d] = true;

    // 3. Find the most annoying, out-of-the-way place for the switch.
    auto reachable = get_all_reachable_distances({0, 0}, blocked, grid);

    pair<int, int> best_switch_pos = {-1, -1};
    int max_dist = -1;

    for (int r = 0; r < N; ++r) {
      for (int c = 0; c < N; ++c) {
        // Must be reachable, empty, and not the entrance/throne
        if (reachable[r][c] > max_dist && !has_switch[r][c] &&
            (r != 0 || c != 0) && (r != N - 1 || c != N - 1)) {
          max_dist = reachable[r][c];
          best_switch_pos = {r, c};
        }
      }
    }

    if (best_switch_pos.first == -1) {
      blocked[i_coord][j_coord][d] = false;
      doors.pop_back();
      break;
    }

    switches.push_back({best_switch_pos.first, best_switch_pos.second, k});
    has_switch[best_switch_pos.first][best_switch_pos.second] = true;

    current_target = best_switch_pos;
  }

  cout << doors.size() << "\n";
  for (const auto &door : doors) {
    cout << door.d << " " << door.i << " " << door.j << " " << door.g << "\n";
  }

  cout << switches.size() << "\n";
  for (const auto &sw : switches) {
    cout << sw.p << " " << sw.q << " " << sw.s << "\n";
  }

  return 0;
}
