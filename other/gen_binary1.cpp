#include <bits/stdc++.h>

using namespace std;

void subSet1(int *arr, int n, int k) {
  if(k == n) {
    for(int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  } else {
    arr[k] = 1;
    subSet1(arr, n, k+1);
    arr[k] = 0;
    subSet1(arr, n, k+1);
  }
}

int main() {
  int setA[4] = {1, 2, 3, 4};
  subSet1(setA, 4, 0);
}