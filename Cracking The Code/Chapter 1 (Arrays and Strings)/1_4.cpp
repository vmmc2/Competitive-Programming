#include <bits/stdc++.h>
#include <sstream>
#include <cmath>

using namespace std;

bool check_permutation(string str){
    int hashtable[128] = {0};
    int tam = (int)str.length();
    if(tam % 2 == 0){ //a string apresenta qtd par de caracteres. Por causa disso, cada caracter tbm deve aparecer em pares 
        for(int i = 0; i < tam; i++){
            hashtable[(int)str[i]]++;
        }
        for(int i = 0; i < 128; i++){
            if((hashtable[i]) % 2 != 0) return false;
        }
        return true;
    }else{ //nesse caso a string possui uma quantidade impar de caracteres. Por causa disso, um caracter deve aparecer um numero impar de vezes
    //e os outros caracteres devem aparecer nessa string aos pares.
        for(int i = 0; i < tam; i++){
            hashtable[(int)str[i]]++;
        }
        int odd = 0;
        for(int i = 0; i < 128; i++){
            if(hashtable[i] % 2 == 1) odd++;
        }
        if(odd == 1) return true;
        else return false;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s = "mamam";
    if(check_permutation(s)){
        cout << "the string is a permutation of a palindrome" << "\n";
    }else{
        cout << "the string is not a permutation of a palindrome" << "\n";
    }
    
    return 0;
}
