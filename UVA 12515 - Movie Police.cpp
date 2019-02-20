#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <string> m;
    vector <string> c;
    string aux, aux2;
    int movies, clips;
    int repeticoes, marcador, mark;
    int contador;
    int i;
    int answer = 0, indmaior;
    //int aux, answer;
    scanf("%d %d", &movies, &clips);
    for(i = 1; i <= movies; i++){
        cin >> aux;
        m.push_back(aux);
    }
    for(i = 1; i <= clips; i++){
        cin >> aux;
        c.push_back(aux);
    }
    for(int j = 0; j < clips; j++){
        answer = (int) 1e9;
        aux = c[j];
        for(int k = 0; k < movies; k++){
            aux2 = m[k];
            if(aux.length() > aux2.length()){
                continue;
            }
            else{
                repeticoes = aux2.length() - aux.length();
                int cur = (int) 1e9;
                for(int a = 0; a <= repeticoes; a++){
                    contador = 0;
                    for(int l = 0; l < (int) aux.length(); l++){
                        if(aux[l] != aux2[l+a]){
                            contador++;
                        }
                        cur = min(cur, contador);
                    }
                    if(contador < answer){
                        answer = contador;
                        indmaior = k;
                    }
                }
            }
        }
        printf("%d\n", indmaior + 1);
    }
    return 0;
}
