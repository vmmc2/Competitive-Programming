#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    map <string, int> dictionary;
    int numcases;
    int numspecies;
    double answer;
    string trash;
    string aux;
    int tam;
    int n;
    scanf("%d", &numcases);
    getchar();
    getchar();
    while(numcases--){
        n = 0;
        while(getline(cin, aux)){
            if(aux.compare("") == 0){
                break;
            }
            else{
                dictionary[aux]++;
            }
            n++;
        }
        for(map<string,int>:: iterator it = dictionary.begin(); it != dictionary.end(); ++it){
            cout << it->first << " ";
            printf("%.4lf\n", (double) it->second*100/n);
        }
        if(numcases){
            puts("");
        }
        dictionary.clear();
    }
    
    return 0;
}
