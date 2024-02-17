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
  int n;
  n = 4;
  int *arr = new int[n];
  // cin >> n;
  nQueen(arr, n, 0);

  delete[] arr;
  
  return 0;
}