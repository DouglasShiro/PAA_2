/* 4)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Comb sort:
*   <comando> Comb_sort < entrada.txt > saida.txt
*   <Complexidade> # pior: O(n²)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  float   shrink_factor = 1.247330950102979;
  int     gap;
  int     swapped = 1;
  int     N = 0;
  int     i;
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

  //Algoritmo Comb sort
  gap = N;
  while ((gap > 1) || swapped) {
    if (gap > 1){
      gap = gap / shrink_factor;
    }
    swapped = 0;
    i = 0;

    while ((gap + i) < N) {
      if (strcmp(entrada_strings[i], entrada_strings[i + gap]) > 0) {
        strcpy(aux, entrada_strings[i]);
        strcpy(entrada_strings[i], entrada_strings[i + gap]);
        strcpy(entrada_strings[i + gap], aux);
        swapped = 1;
      }
      ++i;
    }
  }

  for(i = 0; i < N; i++){
    printf("%s\n", entrada_strings[i]);
  }
  free(entrada_strings);
  return 0;
}
