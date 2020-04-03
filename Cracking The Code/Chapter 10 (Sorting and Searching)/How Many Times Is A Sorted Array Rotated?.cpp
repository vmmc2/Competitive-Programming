#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;


//O algoritmo abaixo so funciona no caso de o array estar rotacionado para a direita.
int rotated_search(vector<int> &v){
    int n = (int)v.size();
    int low = 0;
    int high = n - 1;
    while(low <= high){
        if(v[low] < v[high]) return low; //isso quer dizer que o array ja ta ordenado. Ou seja, basta eu retornar o indice "low"
        int mid = low + (high - low)/2;
        int prev = (mid + n - 1) % n; 
        int next = (mid + 1) % n;
        if(v[mid] < v[prev] && v[mid] < v[next]) return mid;//nesse caso, achei o pivot (que eh quem eu to procurando). retorno o indice dele.
        if(v[low] < v[mid]) low = mid + 1; //corto o espaco de busca
        if(v[mid] < v[high]) high = mid - 1; //corto o espaco de busca
    }
    return -1; //recebi um input invalido.
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v = {1,23,34,55,67,74}; 
    int rot = rotated_search(v);
    if(rot == -1){
        cout << "The array provided in the input is invalid." << "\n";
    }else{
        cout << "The array got rotated: " << rot << " times." <<"\n";
    }
    return 0;
}
