#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//vetor global com o qual eu vou geral o postorder da minha arvore
int newpostorder[8010];
int contador = 0;
//funcao de busca que vai me auxiliar na montagem do postorder
int find(int aux[], int r, int n){
    int i;
    for(i = 0; i < n; i++){
        if(aux[i] == r){
            return i;
        }
    }
    return -1;
}
//funcao que sera utilizada para montar o novo postorder
void novopostord(int in[], int pre[], int n){
    int raiz = find(in, pre[0], n);
    if(raiz != 0){
        novopostord(in, pre+1, raiz);
    }
    if(raiz != n-1){
        novopostord(in+raiz+1, pre+raiz+1, n-raiz-1);
    }
    newpostorder[contador++] = pre[0];

}
//Funcao main
int main(){
    int preorder[8010], postorder[8010], inorder[8010];
    int ok = 1;//A flag vai me auxiliar pra saber se eu consegui gerar
    //um postorder que coincide com o postorder que foi dado na entrada
    int nodes = 0, i = 0;
    scanf("%d", &nodes);
    for(i = 0; i < nodes; i++){
        scanf("%d", &preorder[i]);
    }
    for(i = 0; i < nodes; i++){
        scanf("%d", &postorder[i]);
    }
    for(i = 0; i < nodes; i++){
        scanf("%d", &inorder[i]);
    }
    //Sabemos que o primeiro elemento do preorder eh a raiz da arvore em questao
    //Agora nos resta achar onde esta a raiz da arovre no inorder
    //Assim que eu conseguir encontrar isso
    //eu vou ter (pela propridade do inorder) que todos os elementos antes
    //do raiz sao da subarvore da esquerda e que todos os elementos dps do
    //da raiz sao da subarvore da direita. A ideia eh usar uma recursao e 
    //continuar esse processo ate que a gente encontre o indice 0.
    novopostord(inorder,preorder, nodes);
    //Preenchi o vetor de postorder. Agr eu tenho que checar se ele bate com
    //o que foi dado para a gente na entrada. Se bater, entao existe uma arvore de
    //busca binaria que satisfaz as condicoes. Caso contrario, nao existe essa
    //arvore de busca binaria
    for(i = 0; i < nodes; i++){
        if(newpostorder[i] != postorder[i]){
            ok = 0;
        }
    }
    if(ok == 0){
        printf("no");
    }
    else{
        printf("yes");
    }
    return 0;
}
