#include <bits/stdc++.h>

using namespace std;

void perm(char *arr, int k, int n) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  } else {
    for(int i = k; i < n; i++) {
      swap(arr[k], arr[i]);
      perm(arr, k+1, n);
      swap(arr[i], arr[k]);
    }
  }
}

int main() {
  int n;
  cin >> n;

  char arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  perm(arr, 0, n);

  return 0;
}