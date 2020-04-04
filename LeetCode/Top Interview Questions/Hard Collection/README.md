# IMPORTANT NOTES

## Merge K Sorted Lists
* Basicamente a gente vai iterar por todas as listas presentes no nosso vector de listas. E para cada uma dessas listas, a gente vai 
iterando por todos os nodes e vai jogando eles em uma MinHeap.
* Feito isso, a gente vai esvaziado a nossa MinHeap e vai dando append em uma nova linked list.
* IMPORTANTE: Tem que colocar um dummynode(sentinela) na lista q a gente vai retornar, se nao a gente toma RTE. Na hora de sair da funcao 
a gente "deleta" o dummynode dando o seguinte comando: return dummy->next;
