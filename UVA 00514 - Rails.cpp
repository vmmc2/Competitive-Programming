#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define INF 9999999
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   
    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        vector<int> final(n);
        vector<int> chegada(n);
        for(int i = 0; i < n; i++){
            chegada[i] = i + 1;
        }
        while(true){
            cin >> final[0];
            if(final[0] == 0) break;
            stack<int> pilha;
            for(int i = 1; i < n; i++){
                cin >> final[i];
            }
            int flag = 1; //suponho que vai dar bom
            int indsearch = 0; //index do que eu preciso achar (final)
            int index = 0;//index do que eu to procurando... (chegada)
            while(true){
                if(index >= n) break;
                if(final[indsearch] != chegada[index]){
                    if(pilha.empty()){
                        pilha.push(chegada[index]);
                        index++;
                    }
                    else if(!pilha.empty()){
                        while(true && !pilha.empty()){
                            if(pilha.top() == final[indsearch]){
                                pilha.pop();
                                indsearch++;
                            }else{
                                pilha.push(chegada[index]);
                                index++;
                                break;
                            }
                        }
                    }
                }
                else if(final[indsearch] == chegada[index]){
                    index++;
                    indsearch++;
                }
            }
            if(!pilha.empty()){ //se ainda sobrou algo na pilha... tento retirar
                while(true && !pilha.empty()){
                    if(indsearch > n) break;
                    if(pilha.top() != final[indsearch]){
                        flag = 0;
                        break;
                    }else{
                        pilha.pop();
                        indsearch++;
                    }
                }
            }
            if(flag == 1){
                cout << "Yes" << "\n";
            }else{
                cout << "No" << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
