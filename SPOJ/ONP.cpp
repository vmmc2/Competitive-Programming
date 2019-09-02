#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int pred(char a){
    if(a == '+') return 1;
    if(a == '-') return 2;
    if(a == '*') return 3;
    if(a == '/') return 4;
    if(a == '^') return 5;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int numcasos;
    cin >> numcasos;
    for(int a = 1; a <= numcasos; a++){
        string x;
        string y = "";
        stack<char> pilha;
        cin >> x;
        x += ")";
        pilha.push('(');
        for(int i = 0; i < (int)x.size(); i++){
            if((int)x[i] >= 97 && (int)x[i] <= 122){
                y += x[i];
            }
            else if(x[i] == '('){
                pilha.push('(');
            }
            else if(x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/' || x[i] == '^'){
                while(pilha.top() != '('){
                    if(pred(pilha.top()) >= pred(x[i])){
                        y += pilha.top();
                        pilha.pop();
                    }else{
                        break;
                    }
                }
                pilha.push(x[i]);
            }
            else if(x[i] == ')'){
                while(pilha.top() != '('){
                    y += pilha.top();
                    pilha.pop();
                }
                pilha.pop();
            }
        }
        cout << y << "\n";
    }
    return 0;
}
