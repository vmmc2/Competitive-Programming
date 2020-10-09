#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int a, b, c;
  cin >> a >> b >> c;
  
  if(a + b == c || a + c == b || c + b == a){
  	cout << "Yes" << endl;
  }else{
  	cout << "No" << endl;
  }
  
  return 0;	
}
