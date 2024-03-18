#include <bits/stdc++.h>

using namespace std;

void findLines(vector<pair<int,int>> lines, int n, int start, int end) {
  sort(lines.begin(), lines.end(), [](pair<int, int> a, pair<int, int> b) {
    int diff_a = abs(a.first - a.second);
    int diff_b = abs(b.first - b.second);
    return diff_a > diff_b;
  });

  vector<pair<int, int>> result;

  int current = start;
  int linesCout = 0;
  for(int i = 0; i < n; i++) {
    if(lines[i].first <= current && lines[i].second > current && lines[i].second <= end) {
      linesCout++;
      result.push_back(lines[i]);
      current = lines[i].second;
    }
  }

  cout << linesCout << endl;
  for(auto const& line: result) {
    cout << line.first << " " << line.second << endl;
  }
}

int main() {
  int n;
  // cin >> n;
  n = 10;

  // vector<pair<int, int>> lines(n);
  // for(int i = 0; i < n; i++) {
  //   cin >> lines[i].first >> lines[i].second;
  // }
  vector<pair<int, int>> lines = {
    {1, 2},
    {3, 5},
    {1, 5},
    {2, 4},
    {4, 5},
    {3, 6},
    {2, 7},
    {7, 9},
    {4, 8},
    {1, 3}
  };

  int start, end;
  // cin >> start >> end;
  start = 1;
  end = 9;

  findLines(lines, n, start, end);

  return 0;
}