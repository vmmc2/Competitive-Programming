#include <bits/stdc++.h>
#include <sstream>
#include <cmath>
#define pb push_back
#define mp make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define SQ(a) (a)*(a)
#define INF 999999
#define EPS 1e-9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	int number //permite armazenar valores de -2*(10e8) ate 2*(10e8)
	long long x //permite armazenar valores de -9*(10e18) ate 9*(10e18)
	__int128_t  numero;  //permite armazenar valores de  -10e38 ate 10e38

	double dale; //64 bits para precisao
	long double // 80 bits para precisao

	//PROBLEMA DE ARREDONDAMENTO COM O DOUBLE:
	//Eh perigoso fazer a comparacao entre dois doubles usando o operador (==) pois pode ser que os dois numeros sejam de fato iguais mas devido a erros de precisao
	//do computador, a maquina acuse que esses numeros sao diferentes. Solucao para isso? Usar o EPS: Assuma que dois numeros sao iguais se a diferenca entre eles eh 
	//menor do que uma constante chamada de EPS
	//Na pratica, temos que EPS = 1e-9 (10e-9)
	if(abs(a - b) < 1e-9){
		//a e b sao numeros iguais
	}

	//MACROS: Indicam que algumas linhas de codigo serao alteradas antes do estagio de compilacao do programa. Em C++ indicamos as macros por meio de "#define"

	//LOGARITMOS:
	//The natural logarithm ln(x) of a number x is a logarithm
	//whose base is e = 2.71828 (aprox). Another property of logarithms
	//is that the number of an integer x in base b is floor(logb(x) + 1)
	

	return 0;
}
