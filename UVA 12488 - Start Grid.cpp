
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int begin[24];//vetor que vai guardar a posicao de cada carro no inicio do grid
    int end[24];//vetor que vai guardar a posicao de cada carro no final do grid
    int numcarros; //tamanho do meu vetor
    int i, achei;
    while(scanf("%d", &numcarros) != EOF){
        int ultrapassagens = 0;//numero de ultrapassagens que acontecem em cada caso
        int visitados[24] = {0}; //vou marcar os carros que eu ja visitei e que ja se encontram
        //na sua posicao final
        for(i = 0; i < numcarros; i++){
            scanf("%d", &begin[i]);
        }
        for(i = 0; i < numcarros; i++){
            scanf("%d", &end[i]);
        }
        int carroprocurado;
        int variaveldavez = 0;//guarda o indice do carro que eu to procurando
        while(1){
            int ok = 1;//supondo que ja ta tudo ordenado
            carroprocurado = end[variaveldavez];
            for(i = 0; i < numcarros; i++){
                if(begin[i] == carroprocurado){
                    achei = i;//a variavel achei vai guardar o indice do carro procurado no
                    //vetor de inicio
                    break;
                }
            }
            if(achei == variaveldavez){
                visitados[carroprocurado] = 1;
            }
            else if(achei > variaveldavez){//O carro vai realizar as ultrapassagens
                int temp;
                while(achei != variaveldavez){
                    temp = begin[achei];
                    begin[achei] = begin[achei-1];
                    begin[achei-1] = temp;
                    ultrapassagens++;
                    achei --;
                }
                visitados[carroprocurado] = 1;
            }
            else if(achei < variaveldavez){//O carro foi ultrapassado, entao eu n preciso mexer nele

            }
            for(i = 1; i <=numcarros; i++){
                if(visitados[i] == 0){
                    ok = 0;
                }
            }
            if(ok == 1){
                break;
            }
            variaveldavez++;
        }
        printf("%d\n", ultrapassagens);
    }

    return 0;
}
