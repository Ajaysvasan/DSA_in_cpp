#include <vector>
class Solution {
  bool dfs(std::vector<std::vector<int>> &rooms, std::vector<bool> &visited,
           int room) {
    visited[room] = true;
    for (int key : rooms[room]) {
      if (!visited[key]) {
        dfs(rooms, visited, key);
      }
    }
    return true;
  }

public:
  bool canVisitAllRooms(std::vector<std::vector<int>> &rooms) {
    std::vector<bool> visited(rooms.size(), false);
    dfs(rooms, visited, 0);
    for (bool v : visited) {
      if (!v) {
        return false;
      }
    }
    return true;
  }
};
