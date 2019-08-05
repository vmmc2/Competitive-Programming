#include <bits/stdc++.h>
#include <cmath>
#define pb push_back

using namespace std;

int main(){
    long int a[1010][1010];
    long int r[1010][1010];
    int n, m;
    int i, j, t;
    t = 0;
    while(scanf("%d %d", &n, &m) == 2){
        if(t++){
            printf("\n");
        }
        long int k = n - m + 1,r[k][k], sum = 0;
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                scanf("%ld", &a[n - i - 1][j]); //preenchendo a matriz de acordo com a ordem na qual os números são dados...
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                if(i > 0) a[i][j] += a[i - 1][j];
                if(j > 0) a[i][j] += a[i][j - 1];
                if(i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
            }
        }
        for(i = 0; i < k; i++){
            for(j = 0; j < k; j++){
                r[i][j] = a[i + m - 1][j + m - 1];
                if(i > 0) r[i][j] -= a[i - 1][j + m - 1];
                if(j > 0) r[i][j] -= a[i + m - 1][j - 1];
                if(i > 0 && j > 0) r[i][j] += a[i - 1][j - 1];
            }
        }
        for(i = 0; i < k; i++){
            for(j = 0; j < k; j++){
                printf("%ld\n", r[k - i - 1][j]);
                sum += r[i][j];
            }
        }
        printf("%ld\n", sum);
    }
    return 0;
}
