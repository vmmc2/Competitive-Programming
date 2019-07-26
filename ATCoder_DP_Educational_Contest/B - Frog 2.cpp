#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define MAX 100100

using namespace std;

int main(){
    int numstones;
    vector <int> height;
    int limite;
    int aux;
    int dp[MAX];
    
    scanf("%d %d", &numstones, &limite);
    height.push_back(0);
    for(int i = 1; i <= numstones; i++){
        scanf("%d", &aux);
        height.push_back(aux);
    }
    
    
    
    memset(dp, 1000000, sizeof dp);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = abs(height[1] - height[2]);
    for(int i = 3; i <= numstones; i++){
        for(int k = 1; k <= limite; k++){
            if(i - k >= 1){
                dp[i] = min(dp[i], dp[i - k] + abs(height[i - k] - height[i]));
            }
        }
    }
    printf("%d\n", dp[numstones]);
    return 0;
}
