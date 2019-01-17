#include <bits/stdc++.h>
#include <math.h>
#include <sstream>
#include <string.h>

using namespace std;

int main(){
    vector <int> polinomio;
    int highpower;
    int numcasos;
    int aux;
    int d;
    int i;
    long long x;
    int k;
    int hop, msr;
    long long answer;
    scanf("%d", &numcasos);
    for(int a = 1; a <= numcasos; a++){
        answer = 0;
        scanf("%d", &highpower);
        for(int j = 1; j <= highpower + 1; j++){
            scanf("%d", &aux);
            polinomio.push_back(aux);
        }
        scanf("%d", &d);
        scanf("%d", &k); // k ta indexado como base 1...n
        i = 1;
        msr = 0;
        while(true){
            if(msr >= k){
                break;
            }
            msr += (i*d);
            //printf("msr: %d --- i: %d ---- d: %d\n", msr, i, d);
            i++;
        }
        x = i-1;
        //printf("x: %d\n", x);
        for(int b = 0; b < (int)polinomio.size(); b++){
            answer += (polinomio[b] * pow(x, b));
        }
        printf("%lld\n", answer);
        polinomio.clear();
    }
    return 0;
}
