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

void Comb_sort(int *arr, int size){
  float shrink_factor = 1.247330950102979;
  int gap = size, swapped = 1, swap, i;

  while ((gap > 1) || swapped) {
    if (gap > 1){
      gap = gap / shrink_factor;
    }
    swapped = 0;
    i = 0;

    while ((gap + i) < size) {
      if (arr[i] - arr[i + gap] > 0) {
        swap = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = swap;
        swapped = 1;
      }
      ++i;
    }
  }
return;
}

int main(){


  return 0;
}
