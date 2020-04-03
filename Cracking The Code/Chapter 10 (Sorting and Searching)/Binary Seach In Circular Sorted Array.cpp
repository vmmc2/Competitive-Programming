#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

//Funcao que vai buscar por um numero em um array ordenado de forma circular 
//O array nao pode ter duplicadas.
//Se tiver, nao da pra fazer melhor que O(n). Ou seja, so da pra resolver o problema com Linear Search.
int binary_search_circular_sorted(vector<int> &v, int target){
    int low = 0;
    int high = (int)v.size() - 1;
    while(low <= high){
        int mid = low + (high - low)/2;
        if(v[mid] == target) return mid; //achei o numero, retorno o indice onde ele se encontra.
        //Nesse caso, isso quer dizer que a segunda metade do array ta ordenada. Da pra aplicar binary search aqui.
        if(v[mid] <= v[high]){
            //So que tem que checar pra ver se o numero pode ta ai mesmo. A gente se aproveita do fato desse segmento ta ordenado.
            if(v[mid] <= target && target <= v[high]){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        if(v[low] <= v[mid]){
            if(v[low] <= target && target <= v[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> v = {66,69,90,1,34,54};
    int indx = binary_search_circular_sorted(v, 54);
    if(indx == -1){
        cout << "Element not found in the array." << "\n"; 
    }else{
        cout << "Element found in the array at the index: " << indx << ".\n";
    }
    
    return 0;
}
