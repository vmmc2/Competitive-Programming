#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  ull t = 1, a = 1;
  cin >> n;
  vector<pair<ull,ull>> v(n);
  for(int i = 0; i < n; i++){
  	cin >> v[i].first >> v[i].second;
  }
  
  for(int i = 0; i < n; i++){
  	ull c1 = (t + v[i].first - 1)/v[i].first;
    ull c2 = (a + v[i].second - 1)/v[i].second;
    ull c = max(c1, c2);
    t = c*v[i].first;
    a = c*v[i].second;
  }
  cout << (t + a) << endl;
  
  return 0;
}
