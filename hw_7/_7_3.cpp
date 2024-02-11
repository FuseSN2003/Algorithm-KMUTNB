#include <bits/stdc++.h>

using namespace std;

void permutation(int n, int k, vector<int> &permute, vector<bool> &checked, int *count) {
  if(permute.size() == k) {
    if(permute[0] < permute[1]) {
      *count+=1;
      for(int num: permute) {
        cout << num << " ";
      }
      cout << endl;
    }
  } else {
    for(int i = 1; i <= n; i++) {
      if(checked[i]) continue;
      checked[i] = true;
      permute.push_back(i);
      permutation(n, k, permute, checked, count);
      checked[i] = false;
      permute.pop_back();
    }
  }
}

int main() {
  int n, k, count = 0;
  cin >> n >> k;

  vector<int> permute;
  vector<bool> checked(n + 1, false);

  permutation(n, k, permute, checked, &count);

  cout << count << endl;

  return 0;
}