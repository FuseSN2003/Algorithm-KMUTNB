#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(int *arr, int n) {
  if(n == 1) return arr[0];

  int m = n / 2;
  int lmss = maxSubarraySum(arr, m);
  int rmss = maxSubarraySum(arr+m, n-m);
  int lsum = INT_MIN, rsum = INT_MIN, sum = 0;

  for(int i = m; i < n; i++) {
    sum += arr[i];
    rsum = max(rsum, sum);
  }

  sum = 0;
  for(int i = m - 1; i >= 0; i--) {
    sum += arr[i];
    lsum = max(lsum, sum);
  } 

  return max(max(lmss, rmss), lsum + rsum);
}

int main() {
  int maxNum = INT_MIN;
  int n;
  cin >> n;

  int arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  cout << maxSubarraySum(arr, n);
  
  return 0;
}