#include <bits/stdc++.h>

using namespace std;

void subSet2(int *arr, int n, int k) {
  for(int i = 1; i <= k; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  int j = (k == 0) ? 1 : arr[k] + 1;
  for(int i = j; i <= n; i++) {
    arr[k+1] = i;
    subSet2(arr, n, k+1);
  }
}

int main() {
  int setA[4] = {1, 2, 3, 4};
  subSet2(setA, 4, 0);
}