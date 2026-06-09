#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> indegree(numCourses, 0);
    vector<vector<int>> adj(prerequisites.size());
    for (vector<int> &prerequisite : prerequisites) {
      int course = prerequisite[0];
      int pre = prerequisite[1];
      adj[pre].push_back(course);
      indegree[course]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    int count = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      count++;
      for (int neighbor : adj[node]) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }
    return count == numCourses;
  }
};
