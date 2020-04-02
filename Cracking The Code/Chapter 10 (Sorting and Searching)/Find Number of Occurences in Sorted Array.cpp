#include <bits/stdc++.h>

using namespace std;

//Binary Search modificada que vai retornar a primeira ou a ultima ocorrencia de um elemento procurado no vector.
//Se o elemento nao estiver presente nesse vector, a funcao vai retornar -1.
// fl == 0  --> Primeira ocorrencia. Continuo a busca em direcao aos indices menores.
// fl == 1  --> Ultima ocorrencia. Continuo a busca em direcao aos indices maiores.
int binary_search(vector<int> &v, int target, int fl){
    int start = 0;
    int end = (int)v.size() - 1;
    int ind = -1; //assumo inicialmente que o elemento nao ta presente no meu vector e vou tentar encontra-lo.
    while(start <= end){
        int mid = start + (end - start)/2;
        if(v[mid] == target){
            ind = mid;
            if(fl == 0){
                end = mid - 1;
            }else if(fl == 1){
                start = mid + 1;
            }
        }else if(target < v[mid]){
            end = mid - 1;
        }else if(v[mid] < target){
            start = mid + 1;
        }
    }
    return ind;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v = {1,1,1,2,3,3,3,3,5,5,6,7,7,7,7,7,7,7,7,8,9,9,10};
    int firstind = binary_search(v, 2, 0);
    if(firstind == -1){ //o elemento nao ta presente no array;
        cout << "Count: 0." << "\n";
    }else{
        int lastind = binary_search(v, 2, 1);
        cout << "Count: " << (lastind - firstind + 1) << ".\n";
    }
    return 0;
}
