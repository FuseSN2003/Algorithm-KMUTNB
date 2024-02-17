#include <bits/stdc++.h>

using namespace std;

void subsetSum(int *arr, int *binary, int k, int n, int target) {
  if(k == n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += binary[i] ? arr[i] : 0;
    }

    if(sum == target) {
      for(int i = 0; i < n; i++) {
        if(binary[i]) {
          cout << arr[i] << " ";
        }
      }
      cout << endl;
    }
    return;
  }

  if(!binary[k] && arr[k] <= target) {
    binary[k] = 1;
    subsetSum(arr, binary, k + 1, n, target);
    binary[k] = 0;
    subsetSum(arr, binary, k + 1, n, target);
  }
}

int main() {
  int n, target;
  // cin >> n >> target;
  n = 6;
  target = 6;
  int *arr = new int[n]{1, 2, 3, 4, 5, 6};
  int *binary = new int[n]{0};

  // for(int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  subsetSum(arr, binary, 0, n, target);

  delete[] arr;
  delete[] binary;
  
  return 0;
}