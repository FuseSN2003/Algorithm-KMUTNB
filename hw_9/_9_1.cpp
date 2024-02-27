#include <bits/stdc++.h>

using namespace std;

class Item{
  public:
    int weight;
    int value;
    int originalIdx;

    Item(){}

    Item(int w, int v, int i): weight(w), value(v), originalIdx(i) {}
};

bool compare(Item *i1, Item *i2) {
  return ((double)i1->value / i1->weight) > ((double)i2->value / i2->weight);
}

double fracKnapsack(Item **items, int capacity, int n) {

  sort(items, items+n, compare);
  
  double totalValue = 0.0;
  double remainingCap = capacity;
  double *ratio = new double[n]{0.0};

  for(int i = 0; i < n; i++) {
    if(remainingCap >= items[i]->weight) {
      totalValue += items[i]->value;
      remainingCap -= items[i]->weight;
      ratio[items[i]->originalIdx] = 1.00;
    } else {
      double fraction = remainingCap / items[i]->weight;
      totalValue += items[i]->value * fraction;
      ratio[items[i]->originalIdx] = fraction;

      break;
    }
  }

  for(int i = 0; i < n; i++) {
    cout << fixed << setprecision(2) << ratio[i] << " ";
  }
  cout << endl;

  delete[] ratio;

  return totalValue;
}

int main() {
  int n, capacity;

  // cin >> n >> capacity;
  n = 4;
  capacity = 25;

  Item **items = new Item*[n]{new Item(18, 25, 0), new Item(15, 24, 1), new Item(10, 5, 2), new Item(5, 8, 3)};
  
  // for(int i = 0; i < n; i++) {
  //   items[i] = new Item();
  //   items[i]->originalIdx = i;
  //   cin >> items[i]->weight;
  // }

  // for(int i = 0; i < n; i++) {
  //   cin >> items[i]->value;
  // }

  double result = fracKnapsack(items, capacity, n);

  cout << result;
  
  delete[] items;

  return 0;
}