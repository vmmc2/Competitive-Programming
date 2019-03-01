#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int tam1,tam2,dp[1500][1500];

int main(){
    string frase1,frase2;
    while(getline(cin,frase1)){
        getline(cin,frase2);
        tam1 = frase1.length();
        tam2 = frase2.length();
        //longest Common Subsequence (LCS)
        for(int i = 1 ;i <= tam1 ;i++)
            for(int j = 1; j <= tam2; j++){
                if(frase1[i-1] == frase2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        cout << dp[tam1][tam2] << endl;
    }
    return 0;
}
