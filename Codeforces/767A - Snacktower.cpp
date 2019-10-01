
#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define INF 99999999
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int hashmap[100100] = {0};
    int davez = n;
    for(int i = 0; i < n; i++){
        if(davez != v[i]){
            hashmap[v[i]] = 1;
            printf("\n");
        }else{
            hashmap[davez] = 1;
            while(hashmap[davez] == 1){
                printf("%d ", davez);
                davez--;
            }
            printf("\n");
        }
    }
    return 0;
}
