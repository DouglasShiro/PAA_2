/* 8)
*                          UNIVERSIDADE DE BRASILIA
*                                   1/2016
*                       Projeto e Analise de Algoritmos
*
*                      Douglas Shiro Yokoyama 13/0024902
*
*******************************************************************************
* Agoritmo usando merge e insertion sort:
*   <comando> merge_insert < entrada.txt > saida.txt
*
*******************************************************************************
* merge_insert: Mistura entre o merge sort e o insertion sort. O algoritmo
*               executa como merge sort. A diferenca e que se o tamanho s do
*               subvetor for s <= k entao o subvetor e ordenado usando o
*               insertion sort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MERGE(char **entrada_strings, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    char** L;
    char** R;
    int i, j, k;
    int max = 100;

    L = calloc(n1+1, sizeof(char**));
    R = calloc(n2+1, sizeof(char**));

    for (i = 0; i < n1; i++){
        L[i] = calloc(max, sizeof(char));
        strcpy(L[i], entrada_strings[p+i]);
    }

    for (j = 0; j < n2; j++){
        R[j] = calloc(max, sizeof(char));
        strcpy(R[j], entrada_strings[q+j+1]);
    }
    L[i] = calloc(max, sizeof(char));
    R[j] = calloc(max, sizeof(char));
    strcpy(L[i], "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    strcpy(R[j], "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

    i = 0;
    j = 0;

    for (k = p; k <= r; k++){
        if(strcmp(L[i], R[j]) <= 0){
            strcpy(entrada_strings[k], L[i++]);
            free(L[i-1]);
        }else {
            strcpy(entrada_strings[k], R[j++]);
            free(R[j-1]);
        }

    }

    free(L);
    free(R);
    return;
}

void MERGE_INSERTSORT(char **entrada_strings, int p, int r, int k){
    int q, i, j;
    int s = r - p;
    char aux[100];

    if(s+1 <= k){
      for(i = p+1; i < r+1; i++){
        strcpy(aux, entrada_strings[i]);
        j = i - 1;

        while((j >= p) && ((strcmp(aux, entrada_strings[j])) < 0)){
            strcpy(entrada_strings[j+1], entrada_strings[j]);
            j = j - 1;
            //Contagem de trocas feitas pelo algoritmo
        }
        strcpy(entrada_strings[j+1], aux);
      }
    }else{
      if (p < r){
        q = (p + r)/2;
        /*Merge da metade da esquerda*/
        MERGE_INSERTSORT(entrada_strings, p, q, k);
        /*Merge da metade da direita*/
        MERGE_INSERTSORT(entrada_strings, q+1, r, k );
        /*Merge das partes*/
        MERGE(entrada_strings, p, q, r);
      }
    }
    return;
}

int main(int argc, char* argv[]){
  int     N = 0;
  int     i;
  char    string[100];
  char**  temp = NULL;
  char**  entrada_strings = NULL;
  int k;

  if(argc == 2){

    k = atoi(argv[1]);

    if((k == 4) || (k == 8) || (k == 32) || (k == 64)){

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

      MERGE_INSERTSORT(entrada_strings, 0, N-1, k);

      for(i = 0; i < N; i++){
        printf("%s\n", entrada_strings[i]);
      }
    }else{
      printf("ERRO: valor de k invalido k = %d", k);
    }
  }else{
    printf("\nERRO: Argumentos invalidos;\nFormato dos argumentos: merge_inert N < entrada.txt\n");
  }
  free(entrada_strings);
return 0;
}
