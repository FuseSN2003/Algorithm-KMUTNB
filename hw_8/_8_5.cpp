#include <bits/stdc++.h>

using namespace std;

const int MAX_BOOK = 3;

int partition(int *arr, int l, int r) {
  int pivot = arr[r];
  int i = l - 1;

  for(int j = l; j <= r - 1; j++){
    if(arr[j] < pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  i++;
  swap(arr[i], arr[r]);
  
  return i;
}

void quick_sort(int *arr, int l, int r) {
  if(l < r) {
    int pivot = partition(arr, l, r);
    
    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
  }
}

void backtracking(int *arr, int *binary, int *result, int k, int n, int coupon, int &maxSum) {
  if(k == n) {
    int sum = 0;
    int ct = 0;
    for(int i = 0; i < n; i++) {
      if(binary[i]) {
        sum += arr[i];
        ct++;
      }
    }

    if(sum <= coupon && ct == MAX_BOOK) {
      if(sum > maxSum) {
        maxSum = sum;
        for(int i = 0; i < n; i++) {
          result[i] = binary[i];
        }
      }
    }
  } else {
    int sum = 0;
    for(int i = 0; i < n; i++) {
      if(binary[i]) {
        sum += arr[i];
      }
    }
    if(sum <= coupon) {
      binary[k] = 1;
      backtracking(arr, binary, result, k + 1, n, coupon, maxSum);
      binary[k] = 0;
      backtracking(arr, binary, result, k + 1, n, coupon, maxSum);
    }
  }
}

int main() {
  int n, m;
  // cin >> n >> m;
  n = 8, m = 600;

  int *arr = new int[n]{136, 411, 211, 200, 275, 189, 232, 375};
  int *result = new int[n]{0};
  int *binary = new int[n]{0};
  int maxSum = INT_MIN;
  // for(int i = 0; i < n; i++) {
  //   cin >> arr[i];
  // }

  quick_sort(arr, 0, n - 1);

  backtracking(arr, binary, result, 0, n, m, maxSum);

  int resultCt = 0;
  for(int i = 0; i < n; i++) {
    if(result[i]) {
      resultCt++;
    }
  }

  if(resultCt > 0) {
    for(int i = 0; i < n; i++) {
      if(result[i]) {
        cout << arr[i] << endl;
      }
    }
  } else {
    for(int i = 0; i < MAX_BOOK; i++) {
      cout << 0 << endl;
    }
  }

  delete[] arr;
  delete[] binary;
  delete[] result;
  
  return 0;
}