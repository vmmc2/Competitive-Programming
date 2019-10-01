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
    
    int n, m;
    cin >> m >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    int deubom = 1;
    int hashmap[100100] = {0};
    for(int i = 0; i < n; i++){
        if(i < m - 1){
            //printf("dale\n");
            hashmap[v[i]]++;
            printf("0");
        }else{
            hashmap[v[i]]++;
            deubom = 1;
            for(int j = 1; j <= m; j++){
                if(hashmap[j] == 0){
                    deubom = 0;
                    printf("0");
                    break;
                }
            }
            if(deubom){
                printf("1");
                for(int j = 1; j <= m; j++){
                    hashmap[j]--;
                }
            }
        }
    }
    return 0;
}
