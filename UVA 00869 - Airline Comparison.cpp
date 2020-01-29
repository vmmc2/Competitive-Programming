#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define INF 99999999

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int company1[40][40];
int company2[40][40];

void init(){
    for(int i = 0; i < 40; i++){
        for(int j = 0; j < 40; j++){
            company1[i][j] = 0;
            company2[i][j] = 0;
        }
    }
    return;
}

void floyd_warshall(){
    for(int k = 0; k < 40; k++){
        for(int i = 0; i < 40; i++){
            for(int j = 0; j < 40; j++){
                company1[i][j] = company1[i][j] | (company1[i][k] & company1[k][j]);
                company2[i][j] = company2[i][j] | (company2[i][k] & company2[k][j]);
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        init();
        map<char,int> c;
        for(int i = 0; i < 26; i++){
            c[(char)(65 + i)] = i;
        }
        int numedges;
        cin >> numedges;
        char from, to;
        //company1
        for(int b = 1; b <= numedges; b++){
            cin >> from >> to;
            company1[c[from]][c[to]] = 1;
            company1[c[from]][c[to]] = 1;
        }
        //company2
        cin >> numedges;
        for(int b = 1; b <= numedges; b++){
            cin >> from >> to;
            company2[c[from]][c[to]] = 1;
            company2[c[from]][c[to]] = 1;
        }
        floyd_warshall();
        bool ok = true;
        for(int i = 0; i < 40; i++){
            for(int j = 0; j < 40; j++){
                if(company1[i][j] != company2[i][j]) ok = false;
            }
        }
        if(ok){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
        if(a != numcasos){
            cout << "\n";
        }
    }
    return 0;
}
