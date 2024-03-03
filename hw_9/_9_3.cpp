#include <bits/stdc++.h>

using namespace std;

int platform(vector<pair<double, double>> times) {
  sort(times.begin(), times.end());

  int create = 1;
  for(int i = 0; i < times.size(); i++) {
    for(int j = 0; j < i; j++) {
      if(times[j].second <= times[i].first) {
        break;
      }

      if(j == i - 1) {
        create++;
      }
    }
  }

  return create;
}

int main() {
  int n;
  cin >> n;

  vector<pair<double, double>> times(n);

  for(int i = 0; i < n; i++) {
    cin >> times[i].first >> times[i].second;
  }

  cout << platform(times) << endl;
  
  return 0;
}