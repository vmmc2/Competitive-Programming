# IMPORTANT NOTES

* Em questoes que envolvem strings e hashtables, sempre pergunte ao entrevistador se a string recebida como input eh formada por caracteres da tabela ASCII ou se eh formada por caracteres Unicode. Tambem pergunte oq devemos retornar caso a gente receba uma string vazia ("") como input. Finalmente, lembre-se que vc pode considerar a tabela ASCII (com 128 caracteres) como tambem da pra eu considerar a tabela ASCII extendida (256 caracteres).

* A funcao sort() de C++ nao retorna a string ordernada(ou uma nova string ordernada). Ela faz tudo In-Place. Modificando a string original em si.

* Para resolver o problema de checar se suas duas string sao permutacoes temos duas formas: A primeira eh so da um sort em ambas as strings e checar se elas sao iguais [Time -> O(n*logn) -- Space -> O(1)]. A segunda forma envolve usar uma hashtable [Time -> O(n) -- Space -> O(n)]

* Como proceder na questao para checar se uma string eh uma permutacao de um palindromo: (1) A string apresenta qtd par de caracteres. Por causa disso, cada caracter tbm deve aparecer em pares. No outro caso, a string possui uma quantidade impar de caracteres. Por causa disso, um caracter deve aparecer um numero impar de vezes e os outros caracteres devem aparecer nessa string aos pares.
