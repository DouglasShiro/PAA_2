/* 3)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Shell sort:
*   <comando> Shell_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: O(n) # pior: O(nlog²n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int     N = 0;
  char    value[100];
  int     gap;
  int     i, j;
  char    string[100];
  //char    aux[100];
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

  //Algoritmo Shell sort
  gap = 1;
  while(gap < N) {
    gap = 3*gap+1;
  }
  while( gap > 1){
    gap /= 3;
    for(i = gap; i < N; i++){
      strcpy(value, entrada_strings[i]);
      j = i - gap;
      while (j >= 0 && ((strcmp(value, entrada_strings[j])) < 0)){
        strcpy(entrada_strings[j + gap], entrada_strings[j]);
        j -= gap;
      }
      strcpy(entrada_strings[j + gap], value);
    }
  }

  for(i = 0; i < N; i++){
    printf("%s\n", entrada_strings[i]);
  }
  return 0;
}
