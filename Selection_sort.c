/* 2)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Selection sort:
*   <comando> Selection_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: O(n²) # medio: O(n²) # pior: O(n²)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int     N = 0;
  int     i, j;
  int     menor;
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

  //Algoritmo Selection sort
  for (i = 0; i < (N -1); i++){
    menor = i;
    for (j = (i + 1); j < N; j++) {
      if (strcmp(entrada_strings[j],entrada_strings[menor]) < 0){
        menor = j;
      }
    }
    if (i != menor){
      strcpy(aux, entrada_strings[i]);
      strcpy(entrada_strings[i], entrada_strings[menor]);
      strcpy(entrada_strings[menor], aux);
    }
  }
  for(i = 0; i < N; i++){
    printf("%s\n", entrada_strings[i]);
  }

  free(entrada_strings);
  return 0;
}
