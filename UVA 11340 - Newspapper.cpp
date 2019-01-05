#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main(){
    int numcases;
    int hashtable[256];
    char frase[100000];
    int numletras;
    long long valor;
    unsigned char letra;
    int numlinhas;
    int tam;
    unsigned long long total;
    double value;
    scanf("%d", &numcases);
    for(int i = 1; i <= numcases; i++){
        memset(hashtable, 0, sizeof(hashtable));
        total = 0;
        scanf("%d", &numletras);
        for(int j = 1; j <= numletras; j++){
            cin >> letra >> valor;
            cin.ignore();
            hashtable[(int) letra] = valor; 
        }
        cin >> numlinhas;
        cin.ignore();
        for(int j = 0; j < numlinhas; j++){
            unsigned char c;
			while ((c = cin.get()) != '\n') {
				total += hashtable[(int) c];
			}
        }
        value = (double) total/100.0;
        printf("%.2lf$\n", value);
    }
    return 0;
}
