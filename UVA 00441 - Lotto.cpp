#include <bits/stdc++.h>

using namespace std;

int main(){
    int qtdnums, aux;
    int k;
    vector <int> numbers;
    while(true){
        scanf("%d", &k);
        if(k == 0){
          break;
        }
        for(int i = 1; i <= k; i++){
            scanf("%d", &aux);
            numbers.push_back(aux);
        }
        sort(numbers.begin(), numbers.end());
        for(int a = 0; a < k - 5; a++){
            for(int b = a + 1; b < k - 4; b++){
                for(int c = b + 1; c < k - 3; c++){
                    for(int d = c + 1; d < k - 2; d++){
                        for(int e = d + 1; e < k - 1; e++){
                            for(int f = e + 1; f < k; f++){
                                printf("%d %d %d %d %d %d\n", numbers[a], numbers[b], numbers[c], numbers[d], numbers[e], numbers[f]);
                            }
                        }
                    }
                }
            }
        }
        printf("\n");
        numbers.clear();
    }
    return 0;
}
