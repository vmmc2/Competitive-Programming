#include <bits/stdc++.h>

using namespace std;

int main(){
    long long flag = -1;
    int visitados[10000];//indicando se eu ja visitei os vertices.
    for(int a = 0; a < 10000; a++){
            visitados[a] = 0;
    }
    //1 -> visitado // 0 -> nao visitado
    queue <pair<int,int>> vertices;
    pair <int,int> auxiliar;
    pair <int,int> auxiliar2;
    int i, aux, hola = 1;
    int buttons[10];//vetor para guardar quantos butoes existem
    //O primeiro elemento eh o vertice. O segundo elemento eh o numero de butoes apertados
    int lockcode, unlockcode, numbuttons;
    scanf("%d %d %d", &lockcode, &unlockcode, &numbuttons);
    while(lockcode != 0 || unlockcode != 0 || numbuttons != 0){
        flag = -1;
        for(i = 0; i < numbuttons; i++){
            scanf("%d", &buttons[i]);
        }
        vertices.push(make_pair(lockcode,0));
        visitados[lockcode] = 1;
        while(!vertices.empty()){
            auxiliar = vertices.front();
            if(auxiliar.first == unlockcode){//quer dizer que eu ja cheguei na minha senha
                flag = 69;
                break;
            }
            vertices.pop();
            for(int k = 0; k < numbuttons; k++){
                if(visitados[(auxiliar.first+buttons[k])%10000] == 0){
                    auxiliar2.first = (auxiliar.first + buttons[k])%10000;
                    auxiliar2.second = auxiliar.second + 1;
                    vertices.push(auxiliar2);
                    visitados[(auxiliar.first+buttons[k])%10000] = 1;
                }
            }
        }
        if(flag == -1){
            printf("Case %d: Permanently Locked\n", hola);
        }
        else if(flag == 69){
            printf("Case %d: %d\n", hola, auxiliar.second);//tem que arrumar esse qtd
        }
        hola++;
        //zerando
        for(int a = 0; a < 10000; a++){
            visitados[a] = 0;
        }
        while(!vertices.empty()){
            vertices.pop();
        }
        scanf("%d %d %d", &lockcode, &unlockcode, &numbuttons);
    }
    return 0;
}
