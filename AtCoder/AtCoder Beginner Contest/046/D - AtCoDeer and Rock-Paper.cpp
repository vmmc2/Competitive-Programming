#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  string s;
  cin >> s;
  
  int countg = 0;
  int countp = 0;
  int points = 0;
  
  for(int i = 0; i < (int)s.length(); i++){
    if(s[i] == 'g'){
        if(countp + 1 > countg){
            countg++;
        }else{
            countp++;
            points++;
        }
    }
    else if(s[i] == 'p'){
        if(countp + 1 > countg){
            countg++;
            points--;
        }else{
            countp++;
        }
    }
  }
  cout << points << endl;
  
  return 0;
}
