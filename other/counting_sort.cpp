#include <bits/stdc++.h>

using namespace std;

vector<int> countingSort(vector<int> arr, int n) {
  int maxArr = INT_MIN;
  for(int i = 0; i < n; i++) {
    maxArr = max(maxArr, arr[i]);
  }
  
  vector<int> tempArr(maxArr+1);
  for(int i = 0; i < n; i++) {
    tempArr[arr[i]]++;
  }

  for(int i = 1; i < tempArr.size(); i++) {
    tempArr[i] += tempArr[i - 1];
  }
  
  vector<int> sortedArr(n);
  for(int i = 0; i < n; i++) {
    tempArr[arr[i]]--;
    sortedArr[tempArr[arr[i]]] = arr[i]; 
  }

  return sortedArr;
}

int main() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  arr = countingSort(arr, n);

  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  
  return 0;
}