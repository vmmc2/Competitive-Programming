#include <bits/stdc++.h>
#include <cmath>
#define pb push_back
#define INF 999999

using namespace std;

int main(){
    //Fast I/O 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, W; //n = quantidade de itens disponiveis  // W = capacidade da knapsack
    cin >> n >> W;
    vector<long int> val(n + 1);
    vector<long int> wt(n + 1);
    val[0] = -1, wt[0] = - 1;
    for(int i = 1; i <= n; i++){
        cin >> wt[i] >> val[i];
    }
    long int knapsack[n + 1][W + 1];
    //pre-processing...
    for(int i = 0; i <= n; i++){
        knapsack[i][0] = 0;
    }
    for(int i = 0; i <= W; i++){
        knapsack[0][i] = 0;
    }
    //show time!
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= W; j++){
            if(wt[i] > j){
                knapsack[i][j] = knapsack[i - 1][j];
            }else{
                knapsack[i][j] = max(knapsack[i - 1][j], val[i] + knapsack[i - 1][j - wt[i]]);
            }
        }
    }
    cout << knapsack[n][W] << endl;
    return 0;
}
