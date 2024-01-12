#include <bits/stdc++.h>

using namespace std;

int calFreq(int *arr, int n) {
  unordered_map<int, int> freqMap;

  for(int i = 0; i < n; i++) {
    freqMap[arr[i]]++;
  }

  int maxFreq = INT_MIN;
  int minFreq = INT_MAX;

  for(auto i : freqMap) {
    maxFreq = max(maxFreq, i.second);
    minFreq = min(minFreq, i.second);
  }

  return maxFreq - minFreq;
}

int main() {
  int n;
  cin >> n;

  int *arr = new int[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int result = calFreq(arr, n);

  cout << result;

  return 0;
}