# IMPORTANT NOTES

* A funcao sort() de C++ nao retorna a string ordernada(ou uma nova string ordernada). Ela faz tudo In-Place. Modificando a string original em si.

* Para resolver o problema de checar se suas duas string sao permutacoes temos duas formas: A primeira eh so da um sort em ambas as strings e checar se elas sao iguais [Time -> O(n*logn) -- Space -> O(1)]. A segunda forma envolve usar uma hashtable [Time -> O(n) -- Space -> O(n)]
