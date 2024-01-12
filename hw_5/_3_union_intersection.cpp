#include <bits/stdc++.h>

using namespace std;

void findIntersectionUnion(const vector<int>& a, const vector<int>& b) {
  int n = a.size();
  int m = *max_element(a.begin(), a.end());
  m = max(m, *max_element(b.begin(), b.end()));
  
  vector<int> countingA(m+1, 0);
  vector<int> countingB(m+1, 0);

  for(int i = 0; i < n; i++) {
    countingA[a[i]]++;
    countingB[b[i]]++;
  }

  vector<int> intersect;
  vector<int> uni;

  for (int i = 0; i < n; i++) {
    if (countingA[a[i]] > 0 && countingB[a[i]] > 0) {
      intersect.push_back(a[i]);
    }
    if (countingA[a[i]] > 0) {
      uni.push_back(a[i]);
      countingA[a[i]] = 0;
      countingB[a[i]] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    if (countingB[b[i]] > 0) {
      uni.push_back(b[i]);
      countingB[b[i]] = 0;
    }
  }

  // Output intersection
  for (int num : intersect) {
    cout << num << " ";
  }
  cout << endl;

  // Output union
  for (int num : uni) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  int n;
  
  cin >> n;

  vector<int> a(n);
  vector<int> b(n);

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }

  findIntersectionUnion(a, b);

  return 0;
}