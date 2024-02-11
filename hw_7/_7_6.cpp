#include <bits/stdc++.h>

using namespace std;

int partition(int *arr, int l, int r) {
  int pivot = arr[r];
  int i = l - 1;

  for(int j = l; j <= r - 1; j++) {
    if(arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  i++;
  swap(arr[i], arr[r]);

  return i;
}

void quickSort(int *arr, int l, int r) {
  if(l < r) {
    int pivot = partition(arr, l, r);
    
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
  }
}

void generateBinary(int *arr, int *binary, vector<int> &result, int n, int k, int coupon) {
  if(k == n) {
    int sum = 0, ct = 0;
    for(int i = 0; i < n; i++) {
      if(binary[i] == 1) {
        sum += arr[i];
        ct++;
      }
    }
    if(sum <= coupon && ct == 3) {
      int j = 0;
      int tempSum = 0;
      for(int i = 0; i < result.size(); i++) {
        tempSum += result[i];
      }
      if(sum > tempSum) {
        for(int i = 0; i < n; i++) {
          if(binary[i] == 1) {
            result[j] = arr[i];
            j++;
          }
        }
      }
    } else {
      return;
    }
  } else {
    binary[k] = 1;
    generateBinary(arr, binary, result, n, k+1, coupon);
    binary[k] = 0;
    generateBinary(arr, binary, result, n, k+1, coupon);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  int arr[n];
  int binary[n] = {0};
  vector<int> result(3, 0);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);
  
  generateBinary(arr, binary, result, n, 0, m);

  for(int num: result) {
    cout << num << endl;
  }

  return 0;
}