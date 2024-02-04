#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r) {
  int ls = m - l + 1;
  int rs = r - m;

  int lArr[ls], rArr[rs];
  for(int i = 0; i < ls; i++) {
    lArr[i] = arr[l + i];
  }
  for(int i = 0; i < rs; i++) {
    rArr[i] = arr[m + i + 1];
  }

  int i = 0;
  int j = 0;
  int k = l;
  while(i < ls && j < rs) {
    if(lArr[i] <= rArr[j]) {
      arr[k++] = lArr[i++];
    } else {
      arr[k++] = rArr[j++];
    }
  }

  while(i < ls) {
    arr[k++] = lArr[i];
    i++;
  }
  while(j < rs) {
    arr[k++] = rArr[j];
    j++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if(l < r) {
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  int n;
  cin >> n;

  int arr[n];
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  mergeSort(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}