#include <bits/stdc++.h>

using namespace std;

class TwinGift {
  public:
    int gift1;
    int gift2;

    TwinGift(int g1, int g2) : gift1(g1), gift2(g2) {}
};

int calDiff(TwinGift **gift, int *binary, int n) {
  int elder = 0;
  int younger = 0;

  for (int i = 0; i < n; i++) {
    if (binary[i]) {
      elder += gift[i]->gift1;
      younger += gift[i]->gift2;
    } else {
      elder += gift[i]->gift2;
      younger += gift[i]->gift1;
    }
  }

  return abs(elder - younger);
}

void twinBacktracking(TwinGift **gift, int *binary, int k, int n, int *leastDiff) {
  if(k == n) {
    *leastDiff =  min(*leastDiff, calDiff(gift, binary, n));
  } else {

    binary[k] = 1;
    if(calDiff(gift, binary, k + 1) < *leastDiff) {
      twinBacktracking(gift, binary, k + 1, n, leastDiff);
    }
    binary[k] = 0;
    if(calDiff(gift, binary, k + 1) < *leastDiff) {
      twinBacktracking(gift, binary, k + 1, n, leastDiff);
    }
  }
}

int main() {
  int n;
  int leastDiff = INT_MAX;
  n = 4;
  // cin >> n;

  TwinGift *gift[n];
  int *binary = new int[n]{0};
  gift[0] = new TwinGift(3, 5);
  gift[1] = new TwinGift(7, 11);
  gift[2] = new TwinGift(8, 8);
  gift[3] = new TwinGift(8, 9);

  // for(int i = 0; i < n; i++) {
  //     int gift1, gift2;
  //     cin >> gift1 >> gift2;
  //     gift[i] = new TwinGift(gift1, gift2);
  // }

  twinBacktracking(gift, binary, 0, n, &leastDiff);
  cout << leastDiff << endl;

  delete[] binary;
  
  return 0;
}