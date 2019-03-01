#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

void Calcula(int qtdpessoas){
    int notas[1000]; // variavel para guardar as notas dos alunos
    int i, alunosacima = 0;
    double media = 0;
    double porcentagem;
    for(i = 0; i < qtdpessoas; i++){
        scanf("%d", &notas[i]);
        media = media + notas[i];
    }
    media = media/qtdpessoas;
    for(i = 0; i < qtdpessoas; i++){
        if(notas[i] > media){
            alunosacima++;
        }
    }
    porcentagem = (double)alunosacima/qtdpessoas;
    porcentagem = porcentagem*100;
    printf("%.3f%\n", porcentagem);

}


int main(){
    int i;//variavel auxiliar para eu percorrer o ciclo for
    int numcasos;
    int qtdpessoas;
    scanf("%d", &numcasos);
    for(i = 1; i <= numcasos; i++){
        scanf("%d", &qtdpessoas);
        Calcula(qtdpessoas);
    }
    return 0;
}
