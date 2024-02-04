#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x;
  cin >> n;
  cin >> x;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  bool found = false;
  int minIdx1 = INT_MAX;
  int minIdx2 = INT_MAX;

  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      if(x == arr[i] + arr[j]) {
        found = true;
        minIdx1 = min(i, minIdx1);
        minIdx2 = min(j, minIdx2);
      }
    }
  }

  if(found) {
    cout << minIdx1 << " " << minIdx2;
  } else {
    cout << -1;
  }
  
  return 0;
}