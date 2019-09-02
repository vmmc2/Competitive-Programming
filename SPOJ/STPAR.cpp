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
    while(cin >> n){
        if(n == 0) break;
        vector<int> vetor(n);
        stack<int> pilha;
        for(int i = 0; i < n; i++){
            cin >> vetor[i];
        }
        int flag = 1; //suponho que eu vou conseguir colocar na ordem correta
        int index = 0; //index q eu to checando
        int search = 1; //tenho que buscar pelo 1 primeiro
        while(true){
            if(index >= n) break;
            if(vetor[index] != search){
                if(pilha.empty()){
                    pilha.push(vetor[index]);
                    index++;
                }else{
                    while(true && !pilha.empty()){
                        if(pilha.top() == search){
                            pilha.pop();
                            search++;
                        }else{
                            pilha.push(vetor[index]);
                            index++;
                            break;
                        }   
                    }
                }
            }
            else if(vetor[index] == search){
                search++;
                index++;
            }
        }
        if(!pilha.empty()){
            while(true){
                if(search > n) break;
                if(pilha.top() != search){
                    flag = 0;
                    break;
                }else{
                    pilha.pop();
                    search++;
                }
            }
        }
        if(flag == 1){
            cout << "yes" << "\n";
        }else{
            cout << "no" << "\n";
        }
    }

    return 0;
}
