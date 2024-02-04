#include <bits/stdc++.h>

using namespace std;

int generateBinary(int *arr, int *binary, int n, int k) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      if(binary[i] == 1 && binary[i+1] == 1 ) {
        return 0;
      }
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
      if(binary[i] == 1) {
        sum += arr[i];
      }
    }
    return sum;
  } else {
    binary[k] = 1;
    int sub1 = generateBinary(arr, binary, n, k+1);
    binary[k] = 0;
    int sub2 = generateBinary(arr, binary, n, k+1);
    return max(sub1, sub2);
  }
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  int binary[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << generateBinary(arr, binary, 10, 0);
  
  return 0;
}