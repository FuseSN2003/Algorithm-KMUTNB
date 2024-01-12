#include <bits/stdc++.h>

using namespace std;

bool isSorted(int *arr, int n, int current = 0) {
  if (current == n - 1) {
    return true;
  } else {
    return arr[current] <= arr[current + 1] && isSorted(arr, n, current + 1);
  }
}

int main() {
  int n;
  cin >> n;
  int *arr = new int[n];

  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  if(isSorted(arr, n)) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}