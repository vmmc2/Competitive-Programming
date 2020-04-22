class Solution {
public:
    string longestPalindrome(string s) {
        //treating the conner cases...
        if((int)s.length() == 0) return ""; //isso quer dizer que a minha string eh vazia.
        
        //treating the general cases...
        int answer = 0;
        int low = 0;
        int high = 0;
        string ss;
        int n = (int)s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        //caso base da nossa dp...
        for(int i = 0; i < n; i++){
            dp[i][i] = true; //representa uma substring s[i..i] (com 1 elemento) entao obvio q eh palindromo.
            if(i < n - 1){
                if(s[i] == s[i+1]){
                    dp[i][i + 1] = true;
                }
            }
        }
        //calculando os outros casos da nossa dp
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j || i > j || j == i + 1) continue;
                dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
            }
        }
        //getting the answer;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i > j) continue;
                if(dp[i][j] == true){
                    //cout << i << " " << j << "\n";
                    int temp = j - i + 1;
                    if(temp > answer){
                        answer = temp;
                        low = i;
                        high = j;
                    }
                }
            }
        }
        for(int a = low; a <= high; a++){
            ss += s[a];
        }
        return ss;
    }
};
