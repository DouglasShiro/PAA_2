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

void Selection_sort(int num[], int tam){
  int i, j, min, aux;

  for (i = 0; i < (tam -1); i++){
    min = i;
    for (j = (i + 1); j < tam; j++) {
      if (num[j] < num[min]){
        min = j;
      }
    }
    if (i != min){
      aux = num[i];
      num[i] = num[min];
      num[min] = aux;
    }
  }
return;
}

int main(){


  return 0;
}
