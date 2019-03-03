#include <bits/stdc++.h>

using namespace std;

int main(){
    int numelements, queries;
    int i;
    scanf("%d %d", &numelements, &queries);

    vector <int> elementos (numelements+1, 0);
    for(i = 1; i <= numelements; i++){
        scanf("%d", &elementos[i]);
    }

    vector <int> queriesinicio (numelements+1, 0);
    vector <int> queriesfinal (numelements+1, 0);

    for(i = 1; i <= queries; i++){
        int left, right;
        scanf("%d %d", &left, &right);
        
        queriesinicio[left]++;

        if(right + 1 <= numelements){
            queriesfinal[right+1]++;
        }
    }

    int num_queries_no_indice = 0;
    vector <int> numvezesquerie (numelements+1, 0);

    for(i = 1; i <= numelements; i++){
        num_queries_no_indice += (queriesinicio[i] - queriesfinal[i]);
        numvezesquerie[i] = num_queries_no_indice;
    }

    sort(elementos.begin(), elementos.end());
    sort(numvezesquerie.begin(), numvezesquerie.end());

    long long somamaxima = 0;

    for(i = 1; i <= numelements; i++){
        somamaxima += numvezesquerie[i]*1LL*elementos[i];
    }
    cout << somamaxima << endl;

    return 0;
}
