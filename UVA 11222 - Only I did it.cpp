#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> fulano;
    vector <int> beltrano;
    vector <int> sicrano;
    multimap <int,string> resolvidos;
    int numproblemas;
    int numcasos;
    int aux;
    scanf("%d", &numcasos);
    for(int i = 1; i <= numcasos; i++){
        //1. Beltrano
        scanf("%d", &numproblemas);
        for(int i = 1; i <= numproblemas; i++){
            scanf("%d", &aux);
            resolvidos.insert({aux,"beltrano"});
        }
        //2. Fulano
        scanf("%d", &numproblemas);
        for(int i = 1; i <= numproblemas; i++){
            scanf("%d", &aux);
            resolvidos.insert({aux,"fulano"});
        }
        //3. sicrano
        scanf("%d", &numproblemas);
        for(int i = 1; i <= numproblemas; i++){
            scanf("%d", &aux);
            resolvidos.insert({aux,"sicrano"});
        }
        for(multimap<int,string>:: iterator it = resolvidos.begin(); it != resolvidos.end(); ++it){
            if(resolvidos.count(it->first) == 1){
                if(it->second == "beltrano"){
                    beltrano.push_back(it->first);
                }
                else if(it->second == "fulano"){
                    fulano.push_back(it->first);
                }
                else if(it->second == "sicrano"){
                    sicrano.push_back(it->first);
                }
            }
        }
        printf("Case #%d:\n", i);
        if(beltrano.size() > fulano.size() && beltrano.size() > sicrano.size()){
            printf("1 %d ", beltrano.size());
            for(int j = 0; j < beltrano.size(); j++){
                if(j != beltrano.size()-1){
                    printf("%d ", beltrano[j]);
                }
                else{
                    printf("%d", beltrano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        else if(fulano.size() > beltrano.size() && fulano.size() > sicrano.size()){
            printf("2 %d ", fulano.size());
            for(int j = 0; j < fulano.size(); j++){
                if(j != fulano.size()-1){
                    printf("%d ", fulano[j]);
                }
                else{
                    printf("%d", fulano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        else if(sicrano.size() > beltrano.size() && sicrano.size() > fulano.size()){
            printf("3 %d ", sicrano.size());
            for(int j = 0; j < sicrano.size(); j++){
                if(j != sicrano.size()-1){
                    printf("%d ", sicrano[j]);
                }
                else{
                    printf("%d", sicrano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        else if(beltrano.size() == fulano.size() && beltrano.size() > sicrano.size()){
            printf("1 %d ", beltrano.size());
            for(int j = 0; j < beltrano.size(); j++){
                if(j != beltrano.size()-1){
                    printf("%d ", beltrano[j]);
                }
                else{
                    printf("%d", beltrano[j]);
                }
            }
            printf("\n");
            printf("2 %d ", fulano.size());
            for(int j = 0; j < fulano.size(); j++){
                if(j != fulano.size()-1){
                    printf("%d ", fulano[j]);
                }
                else{
                    printf("%d", fulano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        else if(beltrano.size() > fulano.size() && beltrano.size() == sicrano.size()){
            printf("1 %d ", beltrano.size());
            for(int j = 0; j < beltrano.size(); j++){
                if(j != beltrano.size()-1){
                    printf("%d ", beltrano[j]);
                }
                else{
                    printf("%d", beltrano[j]);
                }
            }
            printf("\n");
            printf("3 %d ", sicrano.size());
            for(int j = 0; j < sicrano.size(); j++){
                if(j != sicrano.size()-1){
                    printf("%d ", sicrano[j]);
                }
                else{
                    printf("%d", sicrano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        //
        else if(fulano.size() ==  sicrano.size() && fulano.size() > beltrano.size()){
            printf("2 %d ", fulano.size());
            for(int j = 0; j < fulano.size(); j++){
                if(j != fulano.size()-1){
                    printf("%d ", fulano[j]);
                }
                else{
                    printf("%d", fulano[j]);
                }
            }
            printf("\n");
            printf("3 %d ", sicrano.size());
            for(int j = 0; j < sicrano.size(); j++){
                if(j != sicrano.size()-1){
                    printf("%d ", sicrano[j]);
                }
                else{
                    printf("%d", sicrano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        //
        else if(beltrano.size() == fulano.size() && fulano.size() == sicrano.size()){
            printf("1 %d ", beltrano.size());
            for(int j = 0; j < beltrano.size(); j++){
                if(j != beltrano.size()-1){
                    printf("%d ", beltrano[j]);
                }
                else{
                    printf("%d", beltrano[j]);
                }
            }
            printf("\n");
            printf("2 %d ", fulano.size());
            for(int j = 0; j < fulano.size(); j++){
                if(j != fulano.size()-1){
                    printf("%d ", fulano[j]);
                }
                else{
                    printf("%d", fulano[j]);
                }
            }
            printf("\n");
            printf("3 %d ", sicrano.size());
            for(int j = 0; j < sicrano.size(); j++){
                if(j != sicrano.size()-1){
                    printf("%d ", sicrano[j]);
                }
                else{
                    printf("%d", sicrano[j]);
                }
            }
            if(i < numcasos)printf("\n");
        }
        //resetando tudo apos um caso de teste
        fulano.clear();
        beltrano.clear();
        sicrano.clear();
        resolvidos.clear();
    }
    return 0;
}
