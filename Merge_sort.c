/* 5)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo Merge sort:
*   <comando> Merge_sort < entrada.txt > saida.txt
*   <Complexidade> # melhor: Theta(nlogn) # medio: Theta(nlogn) # pior: Theta(nlog2n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funcoes de Merge
void MERGE(char **entrada_strings, int p, int q, int r);
void MERGESORT(char **entrada_strings, int p, int r);

int main(){
  int     N = 0;
  int     i, j;
  char    string[100];
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

  //Algoritmo Merge sort
  i = 0;
  /*Durante execucao no linux Ubuntu eh necessario digitar ctrl+d para indicar o EOF no terminal*/
  j = i-1;

  MERGESORT(entrada_strings, 0, j);

  for(i = 0; i <= j; i++){
      printf("%s ", entrada_strings[i]);
  }

return 0;
}

void MERGE(char **entrada_strings, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    char L[n1+1][100];
    char R[n2+1][100];
    int i, j, k;

    for (i = 0; i < n1; i++){
        strcpy(L[i], entrada_strings[p+i]);
    }

    for (j = 0; j < n2; j++){
        strcpy(R[j], entrada_strings[q+j+1]);
    }
    strcpy(L[i], "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    strcpy(R[j], "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

    i = 0;
    j = 0;

    for (k = p; k <= r; k++){
        if(strcmp(L[i], R[j]) <= 0){
            strcpy(entrada_strings[k], L[i++]);
        }else {
            strcpy(entrada_strings[k], R[j++]);
        }
    }

    return;

}

void MERGESORT(char **entrada_strings, int p, int r){
    int q;

    if (p < r){
      q = (p + r)/2;
      /*Merge da metade da esquerda*/
      MERGESORT(entrada_strings, p, q);
      /*Merge da metade da direita*/
      MERGESORT(entrada_strings, q+1, r);
      /*Merge das partes*/
      MERGE(entrada_strings, p, q, r);
    }
    return;
}
