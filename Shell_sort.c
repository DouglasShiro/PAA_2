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

void Shell_sort(int *vet, int size){
  int i, j, value;
  int gap;

  gap = 1;
  while(gap < size) {
    gap = 3*gap+1;
  }
  while( gap > 1){
    gap /= 3;
    for(i = gap; i < size; i++){
      value = vet[i];
      j = i - gap;
      while (j >= 0 && value < vet[j]){
        vet[j + gap] = vet[j];
        j -= gap;
      }
      vet[j + gap] = value;
    }
  }
return;
}

int main(){


  return 0;
}
