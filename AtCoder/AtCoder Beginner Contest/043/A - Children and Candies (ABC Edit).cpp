#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  
  int a1 = 1;
  int an = n;
  int answer = ((a1 + an)*n)/2;
  
  cout << answer << "\n";
  
  return 0;
}
