#include <bits/stdc++.h>

using namespace std;

bool isRotation(string s1, string s2){
    if(s1.length() != s2.length()) return false;
    if(s1.length == 0) return false;
    string s3 = s2 + s2;
    return isSubstring(s3,s1); //funcao que checa se s1 eh uma substring de s3
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    //Checar se a string s2 eh uma rotacao da string s1.
    string s1 = "elefante";
    string s2 = "fanteele";
    //Perceba que a string s1 pode ser dividida sempre em duas partes
    //de tamanhos quaisquer e diferentes de 0 que representam a substring
    //que fica e a substring que foi rotacionada.
    //Exemplo: s1 = x + y.
    //Logo, temos que, se s2 for de fato uma rotacao de s1, teremos que
    //s2 = y + x.
    //Entao fazemos o seguinte: string s3 = s2 + s2 = (y+x)+(y+x) = y+(x+y)+x
    //Perceba que x+y == s1.
    bool ans = isRotation(s1, s2);
    if(ans == true){
        cout << "s2 eh uma rotacao de s1" << "\n";
    }else{
        cout << "s2 nao eh uma rotacao de s1" << "\n";
    }
    return 0;
}
