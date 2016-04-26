/* 7)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*                                 Trabalho 2
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Bubble sort:
*   <comando> Bubble_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: O(n) # medio: O(n²) # pior: O(n²)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int     N = 0;
  int     i, j;
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

  //Algoritmo Bubble sort
  for(i = N-1; i >= 1; i--){
    for(j = 0; j < i; j++){
      if(strcmp(entrada_strings[j], entrada_strings[j+1]) > 0){
        strcpy(aux, entrada_strings[j]);
        strcpy(entrada_strings[j], entrada_strings[j+1]);
        strcpy(entrada_strings[j+1], aux);
      }
    }
  }

  for(i = 0; i < N; i++){
    printf("%s\n", entrada_strings[i]);
  }
  return 0;
}
