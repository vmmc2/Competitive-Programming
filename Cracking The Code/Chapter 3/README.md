# IMPORTANT NOTES

## Sort Stack Problem
* Nesse problema, a gente recebe uma stack na qual os numeros que estao em seu interior nao estao ordenados. A gente tem que ordenar essa 
stack inicial utilizando apenas uma segunda stack como auxilio.
* Vamos chamar a stack input de S1 e a stack auxiliar de S2. O objetivo vai ser deixar a stack S2 ordenada e depois so ir preenchendo a
stack s1 normalmente.
* Inicialmente a gente vai ter um while(!s1.empty()). Se S2 estiver vazia, a gente so transpoe o topo de S1 para S2. Caso contrario, a 
gente tem que fazer algumas comparacoes... 
 1) Se o topo de S1 for maior ou igual que o topo de S2, a gente so transpoe o elemento de S1 para S2
 2) Se o topo de S1 for menor que o topo de S2, a gente salva o topo de S1 em uma variavel, da pop() em S1 e vai passando os elementos de 
    S2 para S1 ate que o topo de S2 seja menor que o valor da variavel, ou ate a gente esvaziar S2. Depois disso, da uma push no valor que
    tava na variavel em S2. E recoloca os elementos de S1 de volta para S2. Para saber quantas transposicoes eu tenho que fazer o ideal eh
    usar um contador. 
