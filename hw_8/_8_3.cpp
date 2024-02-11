#include <bits/stdc++.h>

using namespace std;

bool isValid(int *arr, int k) {
  for(int i = 0; i < k; i++) {
    if(arr[i] == arr[k] || abs(arr[i] - arr[k]) == abs(i - k)) {
      return false;
    }
  }
  return true;
}

void nQueen(int *arr, int n, int k) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  } else {
    for(int i = 0; i < n; i++) {
      arr[k] = i;
      if(isValid(arr, k)) {
        nQueen(arr, n, k + 1);
      }
    }
  }
}

int main() {
  int arr[4], n;
  n = 4;
  // cin >> n;
  nQueen(arr, n, 0);
  
  return 0;
}