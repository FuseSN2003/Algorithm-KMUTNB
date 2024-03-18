#include <bits/stdc++.h>

using namespace std;

int greedy_gift_diff(vector<pair<int, int>> gifts) {
  sort(gifts.begin(), gifts.end());

  int elder_sum = 0;
  int younger_sum = 0;

  for(const auto& gift: gifts) {
    if(elder_sum >= younger_sum) {
      elder_sum += gift.first;
      younger_sum += gift.second;
    } else {
      elder_sum += gift.second;
      younger_sum += gift.first;
    }
  }

  return abs(elder_sum - younger_sum);
}

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> gifts(n);

  for(int i = 0; i < n; i++) {
    cin >> gifts[i].first >> gifts[i].second;
  }

  cout << greedy_gift_diff(gifts) << endl;  
  
  return 0;
}