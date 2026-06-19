#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    vector<pair<int, int>> projects;
    for (int i = 0; i < profits.size(); i++) {
      projects.push_back({capital[i], profits[i]});
    }
    sort(projects.begin(), projects.end());
    priority_queue<int> pq;
    int idx = 0;
    while (k--) {
      while (idx < profits.size() && projects[idx].first <= w) {
        pq.push(projects[idx].second);
        idx++;
      }
      if (pq.empty())
        break;
      w += pq.top();
      pq.pop();
    }
    return w;
  }
};

int main(int argc, char *argv[]) { return 0; }
