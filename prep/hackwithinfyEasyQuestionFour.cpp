#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>

using namespace std;
// This is a graph sum ??
// what the fuck
// Greedy approach
int countSteps(int n) {
  int count = 0;
  while (n > 1) {
    if (n % 2 != 0 && n != 3) {
      if (n <= 5)
        n = n - 1;
      else
        n = (2 * n) / 3;
      cout << n << endl;
      count++;
    }
    n = n / 2;
    count++;
  }
  return count;
}

// graph based approach
int minMoves(int n) {
  if (n <= 1)
    return 0;
  queue<pair<int, int>> q;
  unordered_set<int> visited;
  q.push({n, 0});
  visited.insert(n);
  while (!q.empty()) {
    int current = q.front().first;
    int dist = q.front().second;
    q.pop();
    if (current == 1)
      return dist;
    int next1 = current - 1;
    if (next1 >= 1 && visited.find(next1) == visited.end()) {
      if (next1 == 1)
        return dist + 1;
      q.push({next1, dist + 1});
      visited.insert(next1);
    }
    int next2 = current / 2;
    if (next2 >= 1 && visited.find(next2) == visited.end()) {
      if (next2 == 1)
        return dist + 1;
      q.push({next2, dist + 1});
      visited.insert(next2);
    }
    int next3 = current * 2 / 3;
    if (next3 >= 1 && visited.find(next3) == visited.end()) {
      if (next3 == 1)
        return dist + 1;
      q.push({next3, dist + 1});
      visited.insert(next1);
    }
  }
  return 0;
}

int main() {
  int n;
  cin >> n;
  cout << minMoves(n);
  cout << "\n" << countSteps(n);
  return 0;
}
