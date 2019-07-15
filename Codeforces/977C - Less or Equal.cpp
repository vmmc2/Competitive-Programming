#include <bits/stdc++.h>
#include <cmath>
#define INF 0xffffff
#define pb push_back

using namespace std;

int main(){
    int length, k;
    vector<int> array;
    int aux;
    cin >> length >> k;
    for(int i = 0; i < length; i++){
        scanf("%d", &aux);
        array.pb(aux);
    }
    stable_sort(array.begin(), array.end());
    if(k == 0){
        if(array[0] == 1){
            printf("-1\n");
            return 0;
        }else{
            printf("1\n");
            return 0;
        }
    }
    if(array[k-1] == array[k] || k == 0){
        printf("-1\n");
    }else{
        printf("%d\n", array[k-1]);
    }
    
    return 0;
}
