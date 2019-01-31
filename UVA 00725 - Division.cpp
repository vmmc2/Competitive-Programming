#include <bits/stdc++.h>

using namespace std;

bool checkvalues(int abcde, int fghij){
    map <int,int> data;
    while(abcde != 0){
        data[abcde % 10]++;
        abcde = abcde/10;
    }
    while(fghij != 0){
        data[fghij % 10]++;
        fghij = fghij/10;
    }
    for(map <int,int>::iterator it = data.begin(); it != data.end(); ++it){
        if(it->second != 1){
            return false;
        }
    }
    return true;
}


int main(){
    int N;
    int abcde, fghij;
    int flagone, flagtwo;
    bool hasanswer, spaceanswer = false;
    while(true){
        scanf("%d", &N);
        if(N == 0){ // condicao de parada para executar o programa
            break;
        }
        //condicao para saber se eu devo pular uma linha ou nao apos cada caso de teste
        if(!spaceanswer){
            spaceanswer = true;
        }
        else{
            printf("\n");
        }
        hasanswer = false;
        for(fghij = 1234; fghij <= 98765; fghij++){
            abcde = N * fghij;
            if(abcde > 98765){
                break; //ja vai ter extrapolado um numero que tenha 5 digitos. Ou seja, deu merda
            }
            if(abcde < 10000){
                flagone = abcde * 10; //se fghij < 10000 isso significa que ele eh um numero da forma 0xxxx.
                //isso eh somente uma artimanha pra inserir o digito 0 no numero em questao
            }else{
                flagone = abcde;
            }
            if(fghij < 10000){
                flagtwo = fghij * 10; //se fghij < 10000 isso significa que ele eh um numero da forma 0xxxx.
                //isso eh somente uma artimanha pra inserir o digito 0 no numero em questao
            }else{
                flagtwo = fghij;
            }
            if(checkvalues(flagone, flagtwo)){
                if(abcde < 10000){
                    printf("0%d / %d = %d\n", abcde, fghij, N);
                }
                else if(fghij < 10000){
                    printf("%d / 0%d = %d\n", abcde, fghij, N);
                }
                else{
                    printf("%d / %d = %d\n", abcde, fghij, N);
                }
                hasanswer = true;
            }
        }
        if(hasanswer == false){
            printf("There are no solutions for %d.\n", N);
        }
    }
    return 0;
}
