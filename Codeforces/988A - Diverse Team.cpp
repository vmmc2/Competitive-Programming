#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#define INF 999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int numstudents, teamsize;
	cin >> numstudents >> teamsize;
	vi students(numstudents);
	for(int i = 0; i < numstudents; i++){
		cin >> students[i];
	}
	set<int> formado; //set que contem estudantes com ratings diferentes... o primeiro
	vector<int> porra;
	//vi indices; //contem os indices dos estudantes que eu usei...
	for(int i = 0; i < numstudents; i++){
		if(formado.find(students[i]) == formado.end()){
			formado.insert(students[i]);
			porra.pb(i + 1);
		}
	}
	//printf("%d %d\n", (int)formado.size(), (int)indices.size());
	if((int)formado.size() < teamsize){
		cout << "NO" << "\n";
	}else{
		cout << "YES" << "\n";
		for(int i = 0; i < teamsize; i++){
			cout << porra[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
