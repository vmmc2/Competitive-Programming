#include <bits/stdc++.h>

using namespace std;

int main(){
    vector <int> A;
    vector <int> B;
    vector <int> C;
    long long somaA = 0;
    long long somaB = 0;
    int cursorA = 0, cursorB = 0;
    int tamA = 0, tamB = 0;
    int i = 0, j = 0;
    scanf("%d", &tamA);
    for(i = 0; i < tamA; i++){
        int aux;
        scanf("%d", &aux);
        A.push_back(aux);
    }
    scanf("%d", &tamB);
    for(i = 0; i < tamB; i++){
        int aux;
        scanf("%d", &aux);
        B.push_back(aux);
    }
    i = 0;
    somaA = 0;
    somaB = 0;
    int foi = 0; //assumind que nao entrei em nenhum if
    while(cursorA < A.size() || cursorB < B.size()){
        if(cursorA >= A.size()){
            if(cursorB < B.size()){
                cout << "-1" << endl;
                return 0;
            }
        }
         if(cursorB >= B.size()){
            if(cursorA < A.size()){
                cout << "-1" << endl;
                return 0;
            }
        }
        foi = 0;
        if(cursorA >= A.size() || cursorB >= B.size()){
            cout << "-1" << endl;
            return 0;
        }
        if(somaA == 0 && somaB == 0){
            foi++;
            somaA = A[cursorA];
            somaB = B[cursorB];
        }
        if(somaA == somaB){
            foi++;
            C.push_back(somaA);
            somaA = 0;
            somaB = 0;
            cursorA++;
            cursorB++;

        }
        else if(somaA < somaB){
            foi++;
            if(somaA < somaB && cursorA + 1 >= A.size()){
                cout << "-1" << endl;
                return 0;
            }
            while(somaA < somaB && cursorA + 1 < A.size()){
                if(cursorA + 1 < A.size()){
                    somaA = somaA + A[++cursorA];
                }
                else{
                    cout << "-1" << endl;
                }
                if(somaA == somaB){
                    break;
                }
            }
        }
        else if(somaA > somaB){
            foi++;
            if(somaB < somaA && cursorB + 1 >= B.size()){
                cout << "-1" << endl;
                return 0;
            }
            while(somaA > somaB && cursorB + 1 < B.size()){
                if(cursorB + 1 < B.size()){
                    somaB = somaB + B[++cursorB];
                }
                else{
                    cout << "-1" << endl;
                }  
                if(somaA == somaB){
                    break;
                }
            }
        }
        else{
            cout << "-1" << endl;
            return 0;
        }
        if(foi == 0){
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << C.size() << endl;
    
    return 0;
}
