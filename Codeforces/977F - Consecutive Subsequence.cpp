#include <bits/stdc++.h>
#include <cmath>
#include <sstream>
#include <iostream>
#define pb push_back
#define INF 999999
#define pii pair<int,int>

using namespace std;

typedef long long ll;

int main(){
    int n;
    scanf("%d", &n);
    int array[n];
    map<int,int> dp;
    vector<int> indexes;
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    int ans = 0;
    int lst;
    for(int i = 0; i < n; i++){
        int x = array[i];
        dp[x] = dp[x - 1] + 1;
        if(ans < dp[x]){
            ans = dp[x];
            lst = x; //qual o ultimo elemento da sequencia que eh a resposta?....
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(lst == array[i]){
            indexes.pb(i + 1);
            lst--;
        }
    }
    reverse(indexes.begin(), indexes.end());
    printf("%d\n", ans);
    for(int i = 0; i < (int)indexes.size(); i++){
        printf("%d ", indexes[i]);
    }
    return 0;
}
