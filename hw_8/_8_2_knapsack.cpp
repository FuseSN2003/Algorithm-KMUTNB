#include <bits/stdc++.h>

using namespace std;

class Item {
  public:
    int weight;
    int value;
    
    Item(int w, int v) : weight(w), value(v) {}
};

int knapsackBacktracking(Item **items, int *binary, int target, int k, int n) {  
  if (k == n) {
    int totalWeight = 0;
    int totalValue = 0;
    for (int i = 0; i < n; ++i) {
      if (binary[i] == 1) {
        totalWeight += items[i]->weight;
        totalValue += items[i]->value;
      }
    }

    if(totalWeight <= target) {
      return totalValue;
    } else {
      return INT_MIN;
    }
  } else {
    int left = INT_MIN, right = INT_MIN;
    int totalWeight = 0;

    for(int i = 0; i < n; i++) {
      if(binary[i]) {
        totalWeight += items[i]->weight;
      }
    }

    if(totalWeight <= target) {
      binary[k] = 1;
      left = knapsackBacktracking(items, binary, target, k + 1, n);
      binary[k] = 0;
      right = knapsackBacktracking(items, binary, target, k + 1, n);
    }
    
    return max(left, right);
  }
}


int main() {
  int n, target, weight, value;
  // cin >> n >> target;
  n = 4;
  target = 18;

  Item *items[n];
  int *binary = new int[n]{0};

  items[0] = new Item(12, 8);
  items[1] = new Item(5, 7);
  items[2] = new Item(4, 4);
  items[3] = new Item(2, 2);

  // for(int i = 0; i < n; i++) {
  //   cin >> weight >> value;
  //   items[i] = new Item(weight, value);
  // }

  cout << knapsackBacktracking(items, binary, target, 0, n);

  delete[] binary;

  return 0;
}