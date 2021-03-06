# IMPORTANT NOTES

## About Using (Min/Max)-Heaps In Problems Involving Kth-(Largest/Smallest) Element Inside An Array.
* If we want to find the Kth largest element of an array, we must use a min-heap of size K.
* Otherwise, if we want to find the Kth smallest element of an array we must use a max-heap of size K. 
* In both cases (Min-Heap or Max-Heap) we must push the element into our Heap. After that, we check if the size of our Heap is bigger than K. If that's the case, then we just do a pop() command. Otherwise, we continue doing the traversal through the input array.
* Another thing to take care in this type of problem is that we might have already added an element to our Heap and might encounter this same element again when doing the traversal of our array. So, to avoid adding repeated elements, we can just check it using a map/unordered_map or a set/unordered_set.
* The time complexity of constructing this heap is: O(n*log(k)). But if K is known, then the time complexity will be just: O(n).
* The space complexity of constructing this heap is O(k). Again, if K is known, then the space complexity will be just: O(1).
* Final warning: About this question, it is a good idea to ask the interviewer if we should consider distinct elements or not. Because it is going to affect the solution.

# Kth Largest Element In An Array
* A solucao mais direta possivel seria a seguinte: Realize um sort() no array, de forma que os numeros fiquem ordernados de forma crescente. E simplesmente retorne nums[tam - k]. Onde "tam" eh o tamanho do array. Essa solucao apresenta complexidade O(n*log(n)) e nao faz uso de memoria extra. Ou seja, complexidade espacial: O(1).
* Existe uma segunda solucao que melhora a complexidade temporal, mas em troca (trade-off) exige mais memoria. Essa solucao funciona da seguinte forma: Criamos uma minHeap e vamos adicionando os elementos do nosso vetor nessa minHeap. A cada push() da minHeap, checamos para ver se o tamanho da nossa minHeap se tornou maior do que K. Caso sim, damos um pop(). Feito isso, teremos na raiz/root da nossa minHeap o Kth largest element e simplesmente retornamos minHeap.top(). A complexidade temporal melhora para: O(n*log(k)), entretanto a complexidade espacial piora para O(n).

# Find Peak Element
* Nao coloque (mid - 1) pois dessa forma vc vai estar ignorando um possivel pico da sua solucao e isso vai dar RTE.

# Word Search
* Na questao Word Search, a cada iteracao do floodfill() marque o vertice como visitado, cheque se ele eh igual a letra da vez.
* Se nao for, desmarque o vertice como visitado imediatamente e dê um return logo em seguida.
* Cheque se vc ta na ultima letra da string e se a letra do board eh igual aquela letra especifica. Se for, marque a flag "found" como true e dê um return logo em seguida.
* Ao final de cada iteracao do floodfill(), antes de dar o return, tbm desmarque o vertice para nao dar problema na hora de continuar a busca em outras iteracoes.

# 3Sum
* Primeiro passo para resolver o problema eh ordernar o array de forma crescente.
* Em seguida, nos vamos iterar por todos os elementos do array desde o index 0 ate o index (n - 3) do array. Onde n eh o tamanho do nosso array.
* Quando a gente tiver iterando sobre cada elemento do nosso array dentro do for mais exterior, a gente tem que fazer um condicional importante que vai evitar que a gente lide com repeticoes no nosso vector "ans". A condicao eh a seguinte: if(i == 0 || (i > 0 && nums[i] != nums[i - 1])) ai a gente continua a fazer as paradas descritas abaixo dentro do escopo desse if statement.
* Para cada elemento sobre o qual estamos iterando, fazemos o seguinte: setamos o index low para i + 1 e o index high para o (n - 1). Setamos nossa soma procurada da seguinte maneira: 0 - nums[i] e vamos iterando utilizando two pointers.
* O principal problema eh retirar duplicatas. Para isso, quando achamos uma soma, nos vamos modificando low e high afim de tirar as duplicatas. Modificamos por meio do seguinte: low++ e high--.

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
