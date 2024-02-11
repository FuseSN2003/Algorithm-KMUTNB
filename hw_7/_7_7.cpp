#include <bits/stdc++.h>

using namespace std;

bool isCheck(bool *bin, int n) {
  for(int i = 0; i < n; i += 2) {
    if(bin[i] == bin[i + 1]) {
      return false;
    }
  }
  return true;
}

int subset(bool *bin, int *arr, int k, int n) {
  if(k == n) {
    if(isCheck(bin, n)) {
      int littleSum = 0;
      int bigSum = 0;
      for(int i = 0; i < n; i++) {
        if(bin[i]) {
          bigSum += arr[i];
        } else {
          littleSum += arr[i];
        }
      }
      return abs(bigSum - littleSum);
    }
    return INT_MAX;
  } else {
    bin[k] = true;
    int left =  subset(bin, arr, k + 1, n);
    bin[k] = false;
    int right = subset(bin, arr, k + 1, n);

    return min(left, right);
  }
}

int main() {
  int n;
  cin >> n;
  n *= 2;

  bool bin[n] = {false};
  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  cout << subset(bin, arr, 0, n);

  return 0;
}