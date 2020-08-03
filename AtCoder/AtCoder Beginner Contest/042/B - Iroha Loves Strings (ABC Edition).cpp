#include <bits/stdc++.h>

using namespace std;

bool compare(string s1, string s2){
  if(s1 + s2 < s2 + s1) return true;
  return false;
}

int main(){
	ios_base::sync_with_stdio(false);
  	cin.tie(0);
  
  	int n, l;
  	string answer = "";
  	cin >> n >> l;
  	vector<string> v(n);
  	for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
  	sort(v.begin(), v.end(), compare);
  	for(int i = 0; i < n; i++){
    	answer += v[i];
    }
  	cout << answer << "\n";
}
