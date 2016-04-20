/* 6)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Insertion sort:
*   <comando> Insertion_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: O(n) # medio: O(n²) # pior: O(n²)
*
*******************************************************************************
* 6.1) conta_inversão: numero de inversoes que o vetor contem
*   - inversao: se i > j e A[i] < A[j]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int     N = 0;
  int     i, j;
  int     conta_inversao = 0;
  char    string[100];
  char    aux[100];
  char**  temp = NULL;
  char**  entrada_strings = NULL;

  while (scanf("%s", string) != EOF){
    N++;

    temp = (char**)realloc(entrada_strings, N * sizeof(char*));

    if (temp != NULL) {
      entrada_strings = temp;
      entrada_strings[N-1] = malloc(100 + 1);
      strcpy(entrada_strings[N-1], string);
    }
    else {
      free (entrada_strings);
      puts ("Error (re)allocating memory");
      exit (1);
    }
  }

  //Algoritmo de Insertion Sort
  for(i = 1; i < N; i++){
   	strcpy(aux, entrada_strings[i]);
  	j = i - 1;

  	while((j >= 0) && ((strcmp(aux, entrada_strings[j])) < 0)){
        strcpy(entrada_strings[j+1], entrada_strings[j]);
    		j = j - 1;
        //Contagem de trocas feitas pelo algoritmo
  			conta_inversao++;
  	}
  	strcpy(entrada_strings[j+1], aux);
  }

  for(i = 0; i < N; i++){
    printf("%s\n",entrada_strings[i]);
  }
  printf("%d\n", conta_inversao);

  free(entrada_strings);
  return 0;
}
