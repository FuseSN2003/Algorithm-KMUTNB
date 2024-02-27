#include <bits/stdc++.h>

using namespace std;

int G[10][10] = {
  {0, 1, 1, 1, 1, 0, 0, 0},
  {1, 0, 0, 0, 0, 1, 0, 0},
  {1, 0, 0, 0, 0, 1, 0, 0},
  {1, 0, 0, 0, 0, 0, 1, 0},
  {1, 0, 0, 0, 1, 0, 1, 0},
  {0, 1, 1, 0, 0, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 0, 1},
  {0, 0, 0, 0, 0, 1, 1, 0}
}, visited[10], n;

void dfs(int i, int target, int *ct) {
  int j;
  cout << i << " ";
  if(i == target) {
    cout << endl;
    // cout << "0" << " ";
    *ct += 1;
    return;
  }
  visited[i] = 1;
  for(j = 0; j < n; j++) {
    if(!visited[j] && G[i][j] == 1) {
      dfs(j, target, ct);
    }
  }
  visited[i] = 0;
}

int main() {
  // cin >> n;
  n = 8;
  int ct = 0;

  // for(int i = 0; i < n; i++) {
  //   for(int j = 0; j < n; j++) {
  //     cin >> G[i][j];
  //   }
  // }

  for(int i = 0; i < n; i++) {
    visited[i] = 0;
  }
  dfs(0, 7, &ct);

  cout << endl << ct;
  return 0;
}