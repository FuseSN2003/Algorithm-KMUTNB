#include <bits/stdc++.h>

using namespace std;

int subset(int *arr, int *nums, int n, int k, int &count) {
  if(k == n) {
    count = count + 1;
    bool zero = true;
    for(int i = n - 1; i >= 0; i--) {
      if(arr[i] == 1) {
        cout << nums[i] + 1;
        zero = false;
      }
    }

    if(zero) {
      cout << "0";
    }

    cout << endl;
    return 1;
  } else {
    int sum = 0;
    arr[k] = 0;
    sum += subset(arr, nums, n, k + 1, count);
    arr[k] = 1;
    sum += subset(arr, nums, n, k + 1, count);

    return sum;
  }
}

int main() {
  int n, k, count = 0;
  cin >> n;

  int arr[n];

  for (int i = 1; i <= n; i++) {
    arr[i - 1] = n - i;
  }

  subset(new int[n], arr, n, 0, count);

  cout << count << endl;

  return 0;
}