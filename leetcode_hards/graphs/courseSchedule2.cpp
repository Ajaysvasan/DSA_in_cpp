#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);
    for (vector<int> &p : prerequisites) {
      int course = p[0];
      int pre = p[1];
      adj[pre].push_back(course);
      indegree[course]++;
    }
    queue<int> q;
    vector<int> topoOrder;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      topoOrder.push_back(node);
      for (int neighbor : adj[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }
    if (topoOrder.size() != numCourses)
      return {};
    return topoOrder;
  }
};
