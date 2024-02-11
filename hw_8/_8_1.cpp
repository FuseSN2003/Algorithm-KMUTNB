#include <bits/stdc++.h>

using namespace std;

void subsetSum(int *arr, bool *bin, int k, int n, int target) {
  if(k == n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += bin[i] ? arr[i] : 0;
    }

    if(sum == target) {
      for(int i = 0; i < n; i++) {
        if(bin[i]) {
          cout << arr[i] << " ";
        }
      }
      cout << endl;
    }
    return;
  }

  if(!bin[k] && arr[k] <= target) {
    bin[k] = true;
    subsetSum(arr, bin, k + 1, n, target);
    bin[k] = false;
    subsetSum(arr, bin, k + 1, n, target);
  }
}

int main() {
  int n, target;
  cin >> n >> target;
  int arr[n];
  bool bin[n] = {false};

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  subsetSum(arr, bin, 0, n, target);
  
  return 0;
}