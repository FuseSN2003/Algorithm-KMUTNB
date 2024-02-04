#include <bits/stdc++.h>

using namespace std;

int ct = 0;

int findPow(int a, int n) {
  if(n==0){
    return 1;
  }

  if(n % 2 == 0) {
    return findPow(a, n / 2) * findPow(a, n / 2);
  } else {
    return findPow(a, (n-1)/ 2) * findPow(a, (n-1) / 2) * a;
  }
}

int main() {
  int a, n;
  cin >> a;
  cin >> n;
  cout << findPow(a, n);

  cout << " " << ct;
  
  return 0;
}