#include <bits/stdc++.h>

using namespace std;

class Graph {
  private:
    int V;
    vector<list<int>> adj;
  public:
    Graph(int v);
    void addEdge(int u, int v);
    int shortestPath(int src, int des);
};

Graph::Graph(int v): V(v) {
  adj.resize(v);
};

void Graph::addEdge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
};

int Graph::shortestPath(int src, int des) {
  vector<bool> visited(V, false);
  vector<int> distance(V, 0);
  queue<int> q;

  visited[src] = true;
  q.push(src);

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v : adj[u]) {
      if(!visited[v]) {
        visited[v] = true;
        distance[v] = distance[u] + 1;
        q.push(v);
      }
    }
  }
  return distance[des];
};

int main() {
  int n;
  cin >> n;

  Graph g(n);

  for (int i = 0; i < n; ++i) {
    int u, v;
    cin >> u;
    while (true) {
      cin >> v;
      if (v == -1) break;
      g.addEdge(u, v);
    }
  }

  int start, end;
  cin >> start >> end;

  int result = g.shortestPath(start, end);
  cout << result;

  return 0;
}