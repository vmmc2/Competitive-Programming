#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    int aux;
    int numcasos;
    int numbuildings;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        vector<int> heigths;
        vector<int> widths;
        scanf("%d", &numbuildings);
        for(int i = 0; i < numbuildings; i++){
            scanf("%d", &aux);
            heigths.pb(aux);
        }
        for(int i = 0; i < numbuildings; i++){
            scanf("%d", &aux);
            widths.pb(aux);
        }
        int n = numbuildings;
        int lis[n];
        int lds[n];
        for(int i = 0; i < n; i++){
            lis[i] = lds[i] = widths[i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 0; j <= i - 1; j++){
                //vendo o longest increasing subsequence
                if(heigths[i] > heigths[j]){
                    lis[i] = max(lis[i], lis[j] + widths[i]);
                }
                //vendo o longest decreasing subsequence
                if(heigths[i] < heigths[j]){
                    lds[i] = max(lds[i], lds[j] + widths[i]);
                }
            }
        }
        int maxlis = -1;
        int maxlds = -1;
        for(int i = 0; i < n; i++){
            maxlis = max(maxlis, lis[i]);
            maxlds = max(maxlds, lds[i]);
        }
        if(maxlis >= maxlds){
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", a, maxlis, maxlds);
        }else if(maxlis < maxlds){
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", a, maxlds, maxlis);
        }
    }
    return 0;
}
