# Explicação para alguns problemas do contest

## F - Programming Contest
* A ideia mais simples de cara é fazer um brute-force com backtrack para tentar descobrir qual a maior soma que fica mais próxima (ou igual) do valor ```t``` definido no enunciado. Infelizmente, essa abordagem dá TLE, pois sua complexidade temporal é de: ```O(n^2)``` onde ```n = 40```.
* A solução para isso é a seguinte: Pega o vetor inicial, divide ele em dois vetores "b" e "c" de tamanhos iguais. Feito isso, criamos mais dois vetores "bSum" e "cSum". Chamaremos o backtrack para cada um dos vetores "b" e "c" para calcular todas as possiveis somas menores que ```t``` e as guardaremos nos vetores "bSum" e "cSum". Feito isso, ordenaremos ambos os vetores "bSum" e "cSum". Dps disso, iteraremos pelo vetor "cSum" e realizaremos uma busca binária no vetor "bSum", de forma que a maior das somas seja guardada em uma variável "answer". 
* Adotando essa abordagem, a complexidade temporal da solução fica: ```O(n*2^(n/2))```.
