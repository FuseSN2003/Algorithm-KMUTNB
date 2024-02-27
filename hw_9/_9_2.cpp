#include <bits/stdc++.h>

using namespace std;

double file(int *arr, int n) {
  sort(arr, arr + n);

  double result = 0;

  for(int i = 0; i < n; i++) {
    result += arr[i] * (n - i);
  }

  return result / n;
}

int main() {
  int n;
  // cin >> n;
  n = 6;

  // int *arr = new int[n];
  int *arr = new int[n]{7, 8, 15, 6, 12, 9};

  // for(int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  double result = file(arr, n);

  cout << fixed << setprecision(2) << result << endl;

  delete[] arr;
  
  return 0;
}