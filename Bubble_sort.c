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

void Bubble_sort(){
  int vector[10] = {'vetor'};

  int tamanho = 10;
  int aux;
  int i, j;

  for(i = tamanho-1; i >= 1; i--){
    for(j = 0; j < i; j++){
      if(vector[j] > vector[j+1]){
        aux = vector[j];
        vector[j] = vector[j+1];
        vector[j+1] = aux;
      }
    }
  }
return;
}

int main(){


  return 0;
}
