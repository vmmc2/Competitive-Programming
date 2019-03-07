#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vetor(n);
  int m = 10000000011;
  for (int i = 0; i < n; i++) {
    cin >> vetor[i];
    m = min(m, vetor[i]);
  }
  for (int i = 0; i < n; i++) {
    vetor[i] = vetor[i] - m;
  }
  int curr = 0;
  for (int i = m % n; i < n; i++) {
    if (vetor[i] <= curr) {
      cout << i + 1 << "\n";
      break;
    }
    curr++;
    if (i == n - 1) {
      i = -1;
    }
  }
  return 0;
}
