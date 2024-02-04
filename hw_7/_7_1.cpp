#include <bits/stdc++.h>

using namespace std;

void perm(char *arr, int k, int n) {
  if(k == n) {
    for(int i = 0; i <= n; i++) {
      cout << arr[i];
    }
    cout << endl;
  } else {
    for(int i = k; i <= n; i++) {
      swap(arr[k], arr[i]);
      perm(arr, k + 1, n);
      swap(arr[k], arr[i]);
    }
  }
}

int partition(char arr[], int l, int r) {
  char pivot = arr[r];
  int i = l - 1;

  for(int j = l; j <= r - 1; j++) {
    if(arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  i++;
  swap(arr[i], arr[r]);

  return i;
}

void quickSort(char arr[], int l, int r) {
  if(l < r) {
    int pivot = partition(arr, l, r);

    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
  }
}

int main() {
  int n;
  cin >> n;
  char arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i]; 
  }

  perm(arr, 0, n - 1);
  
  return 0;
}