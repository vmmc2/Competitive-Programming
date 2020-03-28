# IMPORTANT NOTES

# Find Peak Element
* Nao coloque (mid - 1) pois dessa forma vc vai estar ignorando um possivel pico da sua solucao e isso vai dar RTE.

# Search In Sorted Rotated Array
* Tentar achar o pico/breakpoint iterando eh uma ideia ruim porque isso vai levar a complexidade O(n), mesmo que a gente faca duas buscas binarias dps. A melhor maneira eh achar o breakpoint usando busca binaria tbm. Isso garante a complexidade O(log(n)).

# Evaluate Reverse Polish Notation
* Tem que ficar ligado com o lance de usar divisao por inteiro de python3 porque ela aplica o floor() no numero. Oq da merda quando estamos trabalhando com numeros negativos. Pra corrigir isso, quando tem um numero positivo e outro negativo com divisao a gente tira o abs() dos dois, efetua a divisao normalmente e dps multiplica o resultado por (-1) pra ficar negativo de novo.

# Top K Frequent Elements
* Time Complexity -> O(n*Log(k))
* Space Complexity -> O(n)

# Increasing Triplet Subsequence
* 1, If the item is smaller than minOne, we assign minOne to item because minOne records the minimal first item of the triplet.
* 2, If the item is larger than minOne, we assign minTwo to Math.min(minTwo, item) because it means that it can be the 2nd item of the triplet and we use Math.min to find the smaller minTwo.
* 3, If the item is larger than minTwo, we can say that we found the triplet and then we can return true to say there exists a triplet.

# 3Sum
* Primeiro passo para resolver o problema eh ordernar o array de forma crescente.
* Em seguida, nos vamos iterar por todos os elementos do array desde o index 0 ate o index (n - 3) do array. Onde n eh o tamanho do nosso array.
* Para cada elemento sobre o qual estamos iterando, fazemos o seguinte: setamos o index low para i + 1 e o index high para o (n - 1). Setamos nossa soma procurada da seguinte maneira: 0 - nums[i] e vamos iterando utilizando two pointers.
* O principal problema eh retirar duplicatas. Para isso, quando achamos uma soma, nos vamos modificando low e high afim de tirar as duplicatas. Modificamos por meio do seguinte: low++ e high--.
