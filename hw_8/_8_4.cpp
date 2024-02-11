#include <bits/stdc++.h>

using namespace std;

int ct = 0;

int maxCoin(int *arr, int *binary, int n, int k) {
  ct++;
  if(k == n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      if(binary[i] == 1) {
        sum += arr[i];
      }
    }
    return sum;
  } else {
    binary[k] = 1;
    int left = (k == 0 || binary[k - 1] == 0) ? maxCoin(arr, binary, n, k + 1) : 0;
    binary[k] = 0;
    int right = maxCoin(arr, binary, n, k+1);
    return max(left, right);
  }
}

int main() {
  int n;
  n = 10;
  // cin >> n;

  int arr[n] = {30, 10, 8, 20, 11, 12, 25, 13, 20, 19};
  int binary[n] = {0};
  
  // for(int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  int result = maxCoin(arr, binary, n, 0);

  cout << result << endl;
  cout << ct << endl;
  
  return 0;
}