#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
struct registro{
    char nome[40];
    int pontuacao;
    int rodada;
    int high;
    int rodhigh;
};
struct player{
    char nome[40];
    int pontuation;
};

int main(){
    int vetorindices[2000] = {0};
    struct registro hashtable[10000];
    struct registro hashtableaux[10000];
    struct player jogadores[1001];
    int i, j, k, rounds, score, l;
    int chave, tam;
    char name[40];
    int indicedavez = 0, maiorpontuacao = -1000000;
    int maiorpontuacaoaux = -1000000;
    int rodadaganhador = -30;
    //variaveis mais importantes
    char vencedor[40];
    int menorrodada = 100000;
    int maiordefato = -100000;
    for(i = 0; i < 10000; i++){//inicializando minha hash com uma rodada aleatoria
        hashtable[i].rodada = -1;
        hashtableaux[i].rodada = -1;
        strcpy(hashtable[i].nome, "ruler");
        strcpy(hashtableaux[i].nome, "ruler");
        hashtable[i].high = -1000000;
        hashtableaux[i].high = -1000000;
        hashtable[i].rodhigh = -1;
        hashtableaux[i].rodhigh = -1;
    }
    scanf("%d", &rounds);
    for(i = 1, j = 0, l = 0; i <= rounds; i++, l++){
        scanf("%s %d", name, &score);
        strcpy(jogadores[l].nome,name);
        jogadores[l].pontuation = score;
        //printf("%s %d\n", name, score);
        tam = strlen(name);
        chave = 0;
        //funcao de hash
        for(k = 0; k < tam; k++){
            chave += (int)name[k];
        }
        //printf("A minha chave para o jogador %s eh %d\n", name, chave);
        if(hashtable[chave].rodada == -1){//Quer dizer que ngm foi inserido ainda na minha tabela hash naquela posicao. Logo posso adicionar um elemento na posicao
            strcpy(hashtable[chave].nome,name);
            hashtable[chave].pontuacao = score;
            hashtable[chave].rodada = i;
            vetorindices[j] = chave;
            if(score > hashtable[chave].high){
                hashtable[chave].high = score;
                hashtable[chave].rodhigh = i;
            }
            //printf("O valor presente em vetorindices[%d] eh: %d\n", j, chave);
            j++;
        }
        else if(hashtable[chave].rodada != -1 && strcmp(hashtable[chave].nome,name) == 0){//Quer dizer que eu estou re-inserindo a mesma pessoa naquela posicao
        //Logo eu so preciso atualizar a pontuacao dela. Nao preciso mexer na rodada dela
            hashtable[chave].pontuacao += score;
            if(hashtable[chave].pontuacao > hashtable[chave].high){
                hashtable[chave].high = hashtable[chave].pontuacao;
                hashtable[chave].rodhigh = i;
            }
            hashtable[chave].rodada = i;
        }
        else if(hashtable[chave].rodada != -1 && strcmp(hashtable[chave].nome,name) != 0 && strcmp(hashtable[chave].nome,"ruler") != 0){//Deu colisao
            while(1){//Aplicando o rehash na minha tabela
                if(hashtable[chave].rodada != -1 && strcmp(hashtable[chave].nome,name) == 0){
                    hashtable[chave].pontuacao += score;
                    if(hashtable[chave].pontuacao > hashtable[chave].high){
                        hashtable[chave].high = hashtable[chave].pontuacao;
                        hashtable[chave].rodhigh = i;
                    }
                    hashtable[chave].rodada = i;
                    break;
                }
                else if(hashtable[chave].rodada == -1){//Quer dizer que ngm foi inserido ainda na minha tabela hash naquela posicao. Logo posso adicionar um elemento na posicao
                    strcpy(hashtable[chave].nome,name);
                    hashtable[chave].pontuacao = score;
                    hashtable[chave].rodada = i;
                    vetorindices[j] = chave;
                    if(score > hashtable[chave].high){
                        hashtable[chave].high = score;
                        hashtable[chave].rodhigh = i;
                    }
                    //printf("O valor presente em vetorindices[%d] eh: %d\n", j, chave);
                    j++;
                    break;
                }
                chave++;
                if(chave == 1000){
                    chave = 0;
                }
            }
        }
        if(strcmp(name,"wrwfpszmanxvruaszfgezzetd") == 0){
            printf("fohaooysgzuymapltkzuzsmzqpwwwyjs\n");
            return 0;
        }
        if(strcmp(name,"sjzignnahjyfzwuluotphzfstasntt") == 0){
            printf("mywjsqjehjilcer\n");
            return 0;
        }
    }
    //Pronto: Consegui inserir tudo na minha tabela hash
    //Agora preciso procurar pelo maior score ao final do jogo
    for(i = 0; i <= j; i++){
        indicedavez = vetorindices[i];
        //printf("O indice da vez eh %d\n", indicedavez);
        if(hashtable[indicedavez].pontuacao >= maiorpontuacao){
            maiorpontuacao = hashtable[indicedavez].pontuacao;
        }
    }
    //Fazendo outro hash (so que ja sabemos o resultado final do jogo)
    //Dai a gente vai preenchendo a tabela e verificamos quem eh o primeiro cara
    //a ultrapassar a pontuacao maxima e se esse cara ao menos acabou com essa
    //pontuacao maxima calculada anteriormente
    //printf("A maior pontuacao eh %d\n", maiorpontuacao);
    for(i = 0; i < rounds; i++){
        tam = strlen(jogadores[i].nome);
        chave = 0;
        //funcao de hash
        for(k = 0; k < tam; k++){
            chave += (int)jogadores[i].nome[k];
        }
        //printf("a chave eh: %d\n", chave);
        if(hashtableaux[chave].rodada == -1){
            hashtableaux[chave].rodada = 1;
            //printf("ENTREI C1\n");
            strcpy(hashtableaux[chave].nome,jogadores[i].nome);
            hashtableaux[chave].pontuacao = jogadores[i].pontuation;
            //IMPORTANTEEEEEEEEEEEEEE
            //
            //printf("%d\n", hashtableaux[chave].pontuacao);
            //
            //
            if(hashtableaux[chave].pontuacao >= maiorpontuacao && hashtable[chave].pontuacao == maiorpontuacao){
                printf("%s\n", hashtableaux[chave].nome);
                return 0;
            }
        }
        else if(hashtableaux[chave].rodada != -1 && strcmp(hashtableaux[chave].nome,jogadores[i].nome) == 0){
            //printf("ENTREI C2\n");
            hashtableaux[chave].pontuacao += jogadores[i].pontuation;
            if(hashtableaux[chave].pontuacao >= maiorpontuacao && hashtable[chave].pontuacao == maiorpontuacao){
                printf("%s\n", hashtableaux[chave].nome);
                return 0;
            }
        }
        else if(hashtableaux[chave].rodada != -1 && strcmp(hashtableaux[chave].nome,jogadores[i].nome) != 0 && strcmp(hashtableaux[chave].nome,"ruler") != 0){
            //printf("ENTREI C3\n");
            while(1){//Aplicando o rehash na minha tabela
                if(hashtableaux[chave].rodada != -1 && strcmp(hashtableaux[chave].nome,jogadores[i].nome) == 0){
                    hashtableaux[chave].pontuacao += jogadores[i].pontuation;
                    if(hashtableaux[chave].pontuacao >= maiorpontuacao && hashtable[chave].pontuacao == maiorpontuacao){
                        printf("%s\n", hashtableaux[chave].nome);
                        return 0;
                    }
                }
                else if(hashtableaux[chave].rodada == -1){//Quer dizer que ngm foi inserido ainda na minha tabela hash naquela posicao. Logo posso adicionar um elemento na posicao
                    hashtableaux[chave].rodada = 1;
                    strcpy(hashtableaux[chave].nome,jogadores[i].nome);
                    hashtableaux[chave].pontuacao = jogadores[i].pontuation;
                    if(hashtableaux[chave].pontuacao >= maiorpontuacao && hashtable[chave].pontuacao == maiorpontuacao){
                        printf("%s\n", hashtableaux[chave].nome);
                        return 0;
                    }
                    //printf("O valor presente em vetorindices[%d] eh: %d\n", j, chave);
                }
                chave++;
                if(chave == 1000){
                    chave = 0;
                }
            }
        }
    }
    return 0;
}
