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

void MERGE(int *A, int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1+1];
    int R[n2+1];
    int i, j, k;

    for (i = 0; i < n1; i++){
        L[i] = A[p+i];
    }

    for (j = 0; j < n2; j++){
        R[j] = A[q+j+1];
    }
    L[i]= 2147483646;
    R[j] = 2147483646;

    i = 0;
    j = 0;

    for (k = p; k <= r; k++){
        if(L[i] <= R[j]){
            A[k] = L[i++];
        }else {
            A[k] = R[j++];
        }
    }

    return;

}

void MERGESORT(int *A, int p, int r){
    int q;

    if (p < r){
      q = (p + r)/2;
      /*Merge da metade da esquerda*/
      MERGESORT(A, p, q);
      /*Merge da metade da direita*/
      MERGESORT(A, q+1, r);
      /*Merge das partes*/
      MERGE(A, p, q, r);
    }
    return;
}

int main(){

  int A[100000]; /* Array a ser organizado*/
  int i, j, n; /* usado para inserir dados ddos e ser passado como final do vertor*/

  i = 0;

  /*Durante execucao no linux Ubuntu eh necessario digitar ctrl+d para indicar o EOF no terminal*/
  while (scanf("%d  ", &n) != EOF){
      A[i++] = n;
  }

  j = i-1;

  MERGESORT(A, 0, j);

  for(i = 0; i <= j; i++){
      printf("%d ", A[i]);
  }

return 0;
}
