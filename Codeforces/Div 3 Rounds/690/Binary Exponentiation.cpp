#include <bits/stdc++.h>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll binExp(ll a, ll p){
  if(p == 0) return 1;
  ll temp = binExp(a, p/2);
  ll result = temp * temp;
  if(p % 2 != 0) result = result * a;
  return result;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll base = 3;
  ll p = 11;
  
  ll answer = binExp(base, p);
  cout << "Answer: " << answer << "\n";

  return 0;
}
