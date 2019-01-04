#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> stations;
    int n;
    int aux;
    int flag;
    scanf("%d", &n);
    while(n != 0){
        flag = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d", &aux);
            stations.push_back(aux);
        }
        sort(stations.begin(), stations.end());
        aux = 0;
        for(int i = 1; i < n; i++){
            if(stations[i] - aux > 200){
                flag = 1;
                break;
            }
            aux = stations[i];
        }
        if((1422 - stations[n-1])*2 > 200){
            flag = 1;
        }
        if(flag == 1){
            printf("IMPOSSIBLE\n");
        }
        else{
            printf("POSSIBLE\n");
        }
        scanf("%d", &n);
        stations.clear();
    }
    return 0;
}
