#include <bits/stdc++.h>

using namespace std;

int partition(int arr[], int l, int r) {
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

void quickSort(int arr[], int l, int r) {
  if(l < r) {
    int pivot = partition(arr, l, r);
    
    quickSort(arr, l, pivot - 1);
    quickSort(arr, pivot + 1, r);
  }
}

int main() {
  int n;
  cin >> n;

  int arr[n];

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  quickSort(arr, 0, n - 1);

  string s = "";

  for(int i = 0; i < n; i++) {
    s += to_string(arr[i]);
  }
  cout << s << endl;
  
  unordered_map<char, int> consecutiveMap;
  for (int i = 0; i < s.length(); i++) {
    int count = 1;

    while (i < s.length() && s[i] == s[i + 1]) {
      count++;
      i++;
    }
    consecutiveMap[s[i]] = max(consecutiveMap[s[i]], count);
  }

  int maxConsecutive = INT_MIN;
  for(const auto& pair : consecutiveMap) {
    maxConsecutive = max(maxConsecutive, pair.second);
  }

  vector<int> tempMaxConsecutiveNums;
  int maxSize = 0;
  for(const auto &pair : consecutiveMap) {
    if(pair.second == maxConsecutive) {
      tempMaxConsecutiveNums.push_back(pair.first - '0');
      maxSize++;
    }
  }

  int maxConsecutiveNums[maxSize];
  for(int i = 0; i < maxSize; i++) {
    maxConsecutiveNums[i] = tempMaxConsecutiveNums[i];
  }

  quickSort(maxConsecutiveNums, 0, maxSize - 1);

  for(int i = 0; i < maxSize; i++) {
    cout << maxConsecutiveNums[i] << " ";
  }
  cout << endl;

  for(int i = 0; i < s.length(); i++) {
    if(s[i] != s[i+1]) {
      cout << s[i];
    }
  }

  return 0;
}