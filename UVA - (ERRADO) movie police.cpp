#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <string> m;
    vector <string> c;
    string aux, aux2;
    int movies, clips;
    int repeticoes, marcador, mark, misera;
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
    for(int j = 0; j < (int) c.size(); j++){
        answer = 0;
        aux = c[j];
        for(int k = 0; k < (int) m.size(); k++){
            aux2 = m[k];
            if(aux.length() > aux2.length()){
                continue;
            }
            else{
                repeticoes = fabs(aux2.length() - aux.length());
                repeticoes++;
                //cout << repeticoes << endl;
                for(int a = 1, marcador = 0; a <= repeticoes; a++, marcador++){
                    contador = 0;
                    for(int l = marcador, mark = 0; mark < (int)c.size(); l++, mark++){
                        if(c[l] == m[l]){
                            contador++;
                        }
                    }
                    printf("contador: %d\n", contador);
                    if(contador > answer){
                        answer = contador;
                        indmaior = k;
                    }
                }
            }
        }
        printf("%d\n", indmaior);
    }
    return 0;
}
